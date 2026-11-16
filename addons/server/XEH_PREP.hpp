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

// Logistics: the website's crates for this deployment (D-470)
PREP(queryCrates);
PREP(queryCrateContents);
PREP(queryCrateBoxes);
PREP(spawnCrate);

// What clients may ask of the server, checked against who sent it (UNITAF tracker #199)
PREP(clientRequest);
PREP(queryPlayerRights);
PREP(requestSender);
PREP(checkOwnUnit);

// ENDEX, sent by the server once clientRequest has checked who asked (UNITAF tracker #202)
PREP(callENDEX);
