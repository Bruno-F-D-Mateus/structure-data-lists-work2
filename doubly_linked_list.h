
// station
typedef struct Station station;
// stations
typedef struct Stations stations;
// route
typedef struct Route route;
// routes
typedef struct Routes routes;
//inicializa a rota - NULL
routes *initRoutes();
//Insere uma nova paragem - inserção no fim
void createStationEnd(int code, char *name, int qty, routes *myRoutes);
//insere uma nova rota - inserção no início
routes *createRouteBegin(routes *rts);
//apresenta todas as rotas existentes
void printRoutes(routes *myRoutes);
//apresenta todas as paragens de uma determinada rota
void printStation(routes *myRoute);
//apresenta a paragem mais lucrativa de uma determinada rota
void printMaxStation(int code, routes *myRoute);
//elimina uma a paragem de uma determinada rota
void removeStation(int routeCode, routes *myRoute, char *stationName);
//elimina uma rota e todas suas paragens
void removeRoute(int routeCode, routes *myRoute);
//retorna uma determinada rota pelo seu código
routes *getRouteByCode(int code, routes *rts);
//conta o número de rotas existentes
int countRts(routes *rts);
//verifica paragens com o mesmo nome
int verifyStation(stations *sts, char *name);