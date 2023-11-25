
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
void createStationEnd(int code, char *name, int qty, routes *headRoute);
//insere uma nova rota - inserção no início
routes *createRouteBegin(routes *headRoute);
//apresenta todas as rotas existentes
void printRoutes(routes *headRoute);
//apresenta todas as paragens de uma determinada rota
void printStation(routes *myRoute);
//apresenta a paragem mais lucrativa de uma determinada rota
void printMaxStation(int code, routes *headRoute);
//elimina uma a paragem de uma determinada rota
void removeStation(int routeCode, routes *headRoute, char *stationName);
//elimina uma rota e todas suas paragens
routes *removeRoute(int routeCode, routes *headRoute);
//retorna uma determinada rota pelo seu código
routes *getRouteByCode(int code, routes *headRoute);
//conta o número de rotas existentes
int countRts(routes *headRoute);
//verifica paragens com o mesmo nome
int verifyStation(stations *head, char *name);