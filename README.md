# Projet-1re-anne-DUT-Info
Jeu d'infiltration en 2D, en C++ avec la librairie SFML


Cahier des charges

Intitulé du projet : Elaborer un jeu d’infiltration en deux dimensions, en vue aérienne, à l’aide du langage C++ et de la librairie SFML
Description : Il s’agira de concevoir un système de jeu centré autour d’une mécanique d’infiltration. Il faut entendre par là que le joueur devra faire son possible afin d’éviter le combat avec l’ennemi. Il devra donc attentivement étudier les trajectoires et les champs de vision de ceux-ci, ainsi que la topographie des niveaux, par crainte d’être repéré et de recommencer le niveau.
Inspirations : divers ‘classiques’ du jeu d’infiltration, notamment en deux dimensions : Metal Gear sur MSX, Mark Of the Ninja sur PC...

Fonctionnalités prévues : 
Menu d’accueil contenant les champs suivant :
Nouvelle Partie
Sélection de la difficulté
Facile : le joueur est plus résistant aux attaques ennemies, et a accès aux bonus, et les champs de vision ennemis sont réduits. Le temps de réaction des ennemis pourra également être augmenté.
Normal : Le joueur est légèrement plus fragile, et les ennemis plus vigilants. l’utilisation de certains items peut être limitée.
Difficile : le joueur est très vulnérable, et les ennemis très réactifs. Aucun item n’est disponible
Charger une partie
Renvoie vers une partie précédemment sauvegardée, au dernier checkpoint
Sélection des niveaux
Renvoie vers un écran des niveaux précédemment visités
Options
Résolution (Boutons en forme de flèches à gauche et à droite, permettant de changer la taille de la fenêtre. 
Volume (musique/Effets), flèches à gauche et à droite pour monter ou baisser le volume.
Configuration des touches (clavier et/ou manette)
Déplacement animé (plusieurs sprites) du personnage selon les axes x et y dans les niveaux. Il faudra accorder une attention particulière à l’orientation du sprite.
Interface utilisateur dans les niveaux (Jauge de vie, radar sonore)
Génération de map : les maps sont composées de salles successives (niveaux), prédéfinis par nos soins; ces niveaux seront assemblés de façon procédurale.
Apparition d’ennemis dotés de déplacement en 2 dimensions, et de champs de vision. Si le joueur est pris dans un champ de vision, il est repéré, les ennemis deviennent agressifs, et il devient difficile pour le joueur de terminer le niveau.
Mise en place d’un système d’items, autrement dit d’objets attribuant plusieurs fonctionnalités supplémentaires au joueur, lui permettant de faciliter sa progression dans un niveau, basés sur les modèles suivants :
Détection des ennemis, à l’aide d’un radar ou d’un élément sonore.(fichier sonore de plus en plus aigu à mesure que le joueur approche d’un ennemi.)
Pack de soin :  si le joueur marche sur cet objet, ses points de vie augmentent.
Item augmentant la vitesse de déplacement du joueur.
Arme permettant de neutraliser les ennemis, seulement en l’activant dans leur dos; Si le joueur essaie d’attaquer un ennemi de front, celui-ci passera en état d’alerte, et deviendra agressif par rapport au joueur.
Plusieurs types d’ennemis, et d’obstacles environnementaux :
Gardes “basiques”, dotés de champs de vision simples et de positions et itinéraires définis. Ils peuvent entreprendre des actions hostiles par rapport au joueur, et le rechercher si repéré.
Gardes “d’élite”, pourvus de plus de points de vie, et plus “attentifs”. Ils sont également plus agressifs et moins prévisibles, car ils possèdent plusieurs itinéraires.
Caméras de sécurité, fixées à un mur, pouvant alerter les ennemis de la présence du joueur.
Caméras de sécurité “améliorées”, fonctionnant sur le même modèle que les caméras “basiques”, mais dotées d’une arme létale pour le joueur.
Mines disposées dans le niveau, réduisant les points de vie du joueur si celui-ci marche dessus.
Environnement Sonore : Musique d'ambiance et plusieurs fichiers sons associés à chaque action du joueur : déplacement, tir, utilisation d’item, repérage par un ennemi…
Effets visuels : attribution d’un sprite pour plusieurs actions du joueur ou des ennemis : Tir d’arme, explosion de mines...


Fonctionnalités Optionnelles :


Changement de texture du personnage (Skin)
Plusieurs packs de textures
Evolution vers un environnement 3D envisageable
Support Modding Simple (Nouveau ennemis, nouvelle map…)
Arbre de compétence à débloquer au fur et à mesure de la progression dans le jeu.
D’autres objets  à ramasser,débloquer:
Leurre à lancer qui attire l’ennemi
Grenade fumigène pouvant bloquer le champ de vision de l’ennemi
Item d’invisibilité du joueur
D’autres ennemis (au corps à corps, snipers à distance…)
Plusieurs sauvegardes disponible
Portes devant être déverrouillées à l’aide d’un pass se trouvant dans la map ou sur un garde. 
Génération d’effets de lumière : Le joueur ainsi que d’autres entités du niveau peuvent générer de la lumière, sensible à la géographie du niveau (présences d’ombres et de reflets).
Génération de particules suivant l'environnement (eau,feu…).
Trame scénaristique, accompagnée de cinématiques animées
