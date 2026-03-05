#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 100

typedef struct {
    char *name;
    char *type;
    double distanceFromEarth;
} Planet;

typedef struct {
    Planet *planets;
    int length;
} PlanetRepo;


Planet *createPlanet(char *name, char *type, double distanceFromEarth) {
    Planet *p = malloc(sizeof(Planet));
    p->name = (char *) malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(p->name, name);
    p->type = (char *) malloc(sizeof(char) * (strlen(type) + 1));
    strcpy(p->type, type);
    p->distanceFromEarth = distanceFromEarth;
    return p;
}

void destroyPlanet(Planet *p) {
    free(p->name);
    free(p->type);
    free(p);
}

PlanetRepo *createPlanetRepo(int capacity) {
    PlanetRepo *repo = malloc(sizeof(PlanetRepo));
    repo->planets = (Planet *) malloc(sizeof(Planet) * capacity);
    repo->length = 0;
    return repo;
}

void destroyPlanetRepo(PlanetRepo *repo) {
    if (repo == NULL) {
        return;
    }

    for (int i = 0; i < repo->length; i++) {
        destroyPlanet(&repo->planets[i]);
    }
    free(repo);
}

void addPlanet(PlanetRepo *repo) {
    char *name = malloc(sizeof(char) * MAX_TEXT_LENGTH);
    printf("Enter planet name: ");
    scanf("%s", name);
    char *type = malloc(sizeof(char) * MAX_TEXT_LENGTH);
    printf("Enter planet type: ");
    scanf("%s", type);
    double distanceFromEarth;
    printf("Enter distance from Earth: ");
    scanf("%lf", &distanceFromEarth);

    const auto planet = *createPlanet(name, type, distanceFromEarth);
    repo->planets[repo->length] = planet;
    repo->length++;

    free(name);
    free(type);
}

void readPlanet(PlanetRepo *repo) {
    printf("Enter the index of the planet: ");
    int index;
    scanf("%d", &index);
    if (index >= repo->length) {
        printf("Planet index out of bounds.");
    } else {
        const auto planet = repo->planets[index];
        printf("Name: %s\nType: %s\nDistanceFromEarth: %.2lf\n ", planet.name, planet.type, planet.distanceFromEarth);
    }
}

void planetManagement() {
    int capacity = 100;
    PlanetRepo *repo = createPlanetRepo(capacity);

    int command;
    while (true) {
        printf("Enter command (1-exit, 2-add, 3-read): ");
        scanf("%d", &command);
        switch (command) {
            case 1:
                destroyPlanetRepo(repo);
                return;
            case 2:
                addPlanet(repo);
                break;
            case 3:
                readPlanet(repo);
                break;
            default:
                printf("Invalid command\n");
        }
    }
}
