#pragma config(Sensor, S1,     Color,          sensorEV3_Color, modeEV3Color_Color)
#pragma config(Sensor, S3,     Touch,          sensorEV3_Touch)
#pragma config(Motor,  motorA,          Puch,          tmotorEV3_Medium, PIDControl, encoder)
#pragma config(Motor,  motorB,          Tapis1,        tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorD,          Tapis2,        tmotorEV3_Large, PIDControl, encoder)


task tapis();
task color();
task touch();

void move_tapis2(int color);

short codeCouleur =0;
int current_color=0;

int change_Color=0;
int etat_tapis=0;

int hue=0;


task color(){

	while(1){
		codeCouleur = getColorName(S1);
		hue = getColorHue(S1);

		/*if(hue >= 330){
		//if(codeCouleur == 5){
			etat_tapis = 1;
			displayTextLine(6, "rouge");
			playSoundFile("Confirm");
			current_color = 5;
			change_Color = 1;
			wait1Msec(1000);
		}
		else if((hue >=210 && hue <= 240) && hue != 240){
		//else if(codeCouleur == 2){
			etat_tapis = 1;
			displayTextLine(6, "bleu");
			playSoundFile("Blue");
			current_color = 2;
			change_Color = 1;
		}
		else if(hue <= 80 && hue != 0){
		//else if(codeCouleur == 4){
			etat_tapis = 1;
			displayTextLine(6, "jaune");
			playSoundFile("Yellow");
			current_color = 4;
			change_Color = 1;
		}
		else if((hue>= 120 && hue<200) && hue != 130){
		//else if(codeCouleur == 3){
			etat_tapis = 1;
			displayTextLine(6, "vert");
			playSoundFile("Green");
			current_color = 3;
			change_Color = 1;
			wait1Msec(1000);
		}

		else{*/
			displayTextLine(7, "codeCouleur %d", codeCouleur);
		//}

		displayBigTextLine(7, "hue %d", hue);

		if(change_Color){
			wait1Msec(2000);
			change_Color = 0;
			etat_tapis = 2;
		}
	}
}


task tapis(){

	while(1){

		if(etat_tapis == 1)	setMotorSpeed(motorB, 10);
		else if(etat_tapis ==2) setMotorSpeed(motorB, 60);
		else	setMotorSpeed(motorB, 30);

	}
}




void move_tapis2(int color){

	if(color ==5 || color == 4){
		setMotorSpeed(motorD, 20);
	}
	else if(color ==3 || color ==2){
		setMotorSpeed(motorD, -20);
	}
	else
		setMotorSpeed(motorD, 0);

	wait1Msec(1000);
	etat_tapis = 0;
}





task touch(){

	while(1){
		if(getTouchValue(S3) == 1){
			moveMotor(motorA, 360, degrees, 60);
			//resetMotorEncoder(motorA);
		}
	}
}





task main()
{

	startTask(color);
	startTask(tapis);
	startTask(touch);

	while(1){

		displayTextLine(1, "change_Color %d", change_Color);
		if(etat_tapis == 2) move_tapis2(current_color);
	}
	stopAllTasks();
}
