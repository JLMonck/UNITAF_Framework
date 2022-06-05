## UNITAF Logistics

This module handles logistic from the DB attached to the deployment\mission
It works by assigning a master depot that has an ace interact which brings up a menu where you can spawn re-supply crates,vehicles, and make custom boxes with items of your choosing.

### How To Setup
+ Enable Logistics in the cba settings under unitaf - Logistics
+ Place master supply depot, found under Empty - [UNITAF] Logistics
+ Set your UNITAF_operationId to what number you are using, this is to point the data grabbing function to get all the assets tied to the orbat.
+ Start your mission and ace interact with the depot to bring up the menu.
***
### Building crates for the DB

##### Building in 3den with 3den enhanced:


##### Building manually:

The db requires 3 entries:

| Type(description)  | Value example |
| ------------- |:-------------:|
| name(name that shows in logistic menu list)| [USMC] Squad resupply crate           |
| classname(classname of box spawned)        | Box_NATO_Ammo_F     |
| content(Array with type and amount)        |[["rhs_mag_30Rnd_556x45_M855A1_Stanag",50],["rhs_mag_M441_HE",25]]|

