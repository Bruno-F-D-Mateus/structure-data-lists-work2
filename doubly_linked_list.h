
// station
typedef struct Station station;
// stations
typedef struct Stations stations;
// route
typedef struct Route route;
// routes
typedef struct Routes routes;

stations *initRoutes();

stations *initStations();

routes *createRoute(routes *rts);

stations *createStation(stations *sts, char *name, int qty);

int getMaxQtySation(int code, routes *rts);

station *getMaxStation(stations *comingSts);

route *getRouteByCode(int code, routes *rts);

int countRts(routes *rts);

int verifyStation(stations *sts, station *st);