
// station
typedef struct Station station;
// stations
typedef struct Stations stations;
// route
typedef struct Route route;
// routes
typedef struct Routes routes;

stations *initStations();

routes *initRoutes();

stations *createStation(stations *sts, char *name, int qty);

void *createRoute(routes *rts);

void printRoutes(routes *myRoutes);

void getMaxQtyStation(int code, routes *rts);

stations *getMaxStation(stations *comingSts);

routes *getRouteByCode(int code, routes *rts);

int countRts(routes *rts);

int verifyStation(stations *sts, stations *st);