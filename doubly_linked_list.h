
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

void createStationEnd(int code, char *name, int qty, routes *myRoutes);

routes *createRouteBegin(routes *rts);

void printRoutes(routes *myRoutes);

void printStation(routes *myRoute);

void printMaxStation(int code, routes *myRoute);

void removeStation(int routeCode, routes *myRoute, char *stationName);

routes *getRouteByCode(int code, routes *rts);

int countRts(routes *rts);

int verifyStation(stations *sts, char *name);