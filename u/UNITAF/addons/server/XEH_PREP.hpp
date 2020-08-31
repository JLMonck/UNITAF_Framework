// initialize Database
PREP(initDatabase);

// Queries - Server
PREP(queryORBATGroups);

// Queries - Client
PREP(queryPlayerData);
PREP(queryPlayerInventory);
PREP(queryPlayerArsenal);

// Server setters
PREP(setORBATGroups);
PREP(makeCurator);

// Special stuff
PREP(addToCurators);