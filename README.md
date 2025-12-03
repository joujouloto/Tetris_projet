Je tourne sous Windows 11. Téléchargez la dernière version de codeblocks.

Téléchargez mon code. Cliquez sur le fichier cbp. Cela va ouvrir codeblock. Il faut télécharger SDL3_image-devel-3.2.4-mingw et SDL3-devel-3.2.16-mingw. Ajoutez les via search directories via builld options de codeblocks. Faites un clic droit et cliquez sur build options, choisissez search directories et incluez SDL3_image-devel-3.2.4-mingw et SDL3-devel-3.2.16-mingw. 

Ensuite revenez sur codeblock. Allez dans l’explorateur de fichiers à gauche de l’ecran et faites clic droit sur le nom du projet « JeuDelaVie ». Allez dans « Build options ». Allez dans « Linker settings »

Ajoutez dans la colonne « Other linker options » « SDL3,dll » et « SDL3_image,dll ». Ensuite allez dans « Search directories » , incluez « include » et « lib » de SDL3 puis faire de même avec SDL3_ttf. Les fichiers que vous avez téléchargés il se trouve des dossiers lib et include, ce sotn ces dossiers dont je parle (là où il y a SDL3 et SDL3_image.

Compilez et run le projet. Normalement ça marche ! Vous avez réussi ! Bravo !
