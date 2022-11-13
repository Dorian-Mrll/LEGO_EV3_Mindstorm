int select=0;
int etat=0;

task affichage(){
	displayCenteredBigTextLine(1, "Veuillez");
	displayCenteredBigTextLine(5, "selectionner");
	displayCenteredBigTextLine(9, "le bouton princiapal");
	displayCenteredBigTextLine(13, "pour commencer");
}


task affichage2(){
	displayCenteredTextLine(3, "BTN gauche = mode manuel");
	displayCenteredTextLine(5, "BTN droite = mode auto");
	displayCenteredTextLine(7, "BTN du bas = arreter le programme");
}



task buttons(){

	if(getButtonPress(buttonLeft) == true){
			select = 1;
	}
	else if(getButtonPress(buttonRight) == true){
			select = 2;
	}
	else if(getButtonPress(buttonDown) == true){
			select = 3;
	}
}


task main()
{

	while(getButtonPress(buttonEnter) != true){
			startTask(affichage);
	}
	stopTask(affichage);
	eraseDisplay();


	while(1){





		startTask(affichage2);

		startTask(buttons);
		if(select == 1)setMotorSpeed(motorB, 50);
			else if(select == 2)setMotorSpeed(motorD, 50);
			else if(select == 3)
			{	eraseDisplay();
			displayCenteredBigTextLine(3, "STOP PROGRAMME");
			delay(500);
			stopAllTasks();
			}

	}
}
