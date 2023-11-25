
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

void getMaxQtyStation(int code, routes *rts);

stations *getMaxStation(stations *comingSts);

routes *getRouteByCode(int code, routes *rts);

int countRts(routes *rts);

int verifyStation(stations *sts, char *name);

char* toLower(char *str);

//Métodos Getter e Setter
stations *getStationHead(routes *myRoutes);