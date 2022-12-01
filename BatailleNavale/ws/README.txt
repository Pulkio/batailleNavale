---------README---------

Auteur : Guillaume COBAT
Groupe : B1
Projet : Bataille Navale

Le projet a été réalisé dans son ensemble, il n'y a pas de bug connu.

Le makefile permet de compiler différentes classes :

------------------------------------------------------

NomClasse : commande

CBateau : "make compilCBateau"
testCBateau : "make compilTestCBateau"

CArmada : "make compilCArmada"
testCArmada : "make compilTestCArmada"

CGui : "make compilCGui"
testCGui : "make compilTestCGui"

CCoups : "make compilCCoups"

CSocket : "make compilCSocket"

CCLientSocket : "make compilCClientSocket"

CServerSocket : "make compilCServerSocket"

CJoueur : "make compilCjoueur"

CJoueurCli : "make compileCJoueurCli"

CJoueurServ : "make compilCJoueurServ"

--------------------------------------------------------

La commande :

- "make deleteAll" permet de supprimer tous les fichiers du .bin

- "make testCBateau" appelle deleteAll, compilCBateau et compilTestCBateau

- "make testCArmada" appelle deleteAll, compilCBateau, compilCArmada et compilTestCArmada

- "make testCGui" appelle deleteAll, compilCCoups, compilCBateau, compilCArmada, compilCGui, compilTestCGUI

- "make lanceurFinal" appelle deleteAll, compilCBateau, compilCArmada, compilCCoups, 
compilCGui, compilCSocket, compilCClientSocket, compilCServerSocket, compilCJoueur, compilCJoueurCli, compilCJoueurServ.

------------------------------------------------------------

Les classes de tests sont :

testCBateau, testCArmada et testCGui.

------------------------------------------------------------

Vous retrouverez le fichier flotille.txt dans le dossier ws, vous pouvez ainsi changer la composition de votre flotte.

							


						




