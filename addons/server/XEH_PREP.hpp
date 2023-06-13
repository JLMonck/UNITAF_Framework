// initialize Database
PREP(initDatabase);

// Connect / Disconnect / Kicked handlers
PREP(onConnect);
PREP(onDisconnect);
PREP(onKicked);

// Queries - Server
PREP(queryORBATGroups);
PREP(queryFullORBAT);

// Queries - Client
PREP(queryPlayerData);
PREP(queryPlayerInventory);
PREP(queryPlayerArsenal);

// Server setters
PREP(setFullORBAT);
PREP(setORBATGroups);
PREP(makeCurator);

// Special stuff
PREP(addToCurators);
