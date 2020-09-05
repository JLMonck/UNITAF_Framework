// initialize Database
PREP(initDatabase);

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