// initialize Database
PREP(initDatabase);

// Connect / Disconnect / Kicked handlers
PREP(onConnect);
PREP(onDisconnect);
PREP(onKicked);
PREP(logPresence);

// Queries - Server
PREP(queryORBATGroups);
PREP(queryFullORBAT);

// Queries - Client
PREP(queryPlayerData);
PREP(queryPlayerInventory);
PREP(queryPlayerArsenal);

// Server setters
PREP(setFullORBAT);
PREP(queryMission);
PREP(setORBATGroups);
PREP(makeCurator);

// Special stuff
PREP(addToCurators);
