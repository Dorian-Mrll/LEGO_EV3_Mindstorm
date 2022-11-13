short codeCouleur =0;
int change_Color=0;
int etat=0;

int current_color=0;

task tapis();
task tapis_low();
task tapis_fast();
task color();
task poussoir();



task color(){

	codeCouleur = getColorName(S1);

	if(codeCouleur == 2){
		stopTask(tapis);
		startTask(tapis_low);
		displayTextLine(6, "bleu");
		current_color = 3;
		change_Color = 1;
	}
	else if(codeCouleur == 4){
		stopTask(tapis);
		startTask(tapis_low);
		displayTextLine(6, "jaune");
		current_color = 5;
		change_Color = 1;
	}
	else if(codeCouleur == 5){
		stopTask(tapis);
		startTask(tapis_low);
		displayTextLine(6, "rouge");
		current_color = 5;
		change_Color = 1;
		//setMotorSpeed(motorD, 20);
		wait1Msec(1000);
	}
	else if(codeCouleur == 3){
		stopTask(tapis);
		startTask(tapis_low);
		displayTextLine(6, "vert");
		current_color = 3;
		change_Color = 1;
		//setMotorSpeed(motorD, -20);
		wait1Msec(1000);
	}
	else{
		displayTextLine(7, "codeCouleur %d", codeCouleur);
		setMotorSpeed(motorD, 0);
	}
}


task tapis(){

	setMotorSpeed(motorB, 30);
}


task tapis_fast(){
	setMotorSpeed(motorB, 60);
}

task tapis_low(){
	setMotorSpeed(motorB, 10);
}



void move_tapis2(int color){

	if(color ==5)
		setMotorSpeed(motorD, 20);
	else if(color ==3)
		setMotorSpeed(motorD, -20);

	wait1Msec(1000);
}


task poussoir(){
	if(getTouchValue(S3) == 1){

			moveMotor(motorA, 360, degrees, 60);
			resetMotorEncoder(motorA);
	}
}





task main()
{
	SensorType[S1] = sensorEV3_Color;
	setSensorMode(S1, modeEV3Color_Color);
	SensorType[S3] = sensorEV3_Touch;


	while(1){


		if(etat == 2)	{
			startTask(tapis_fast);
			wait1Msec(1000);
			move_tapis2(current_color);
			stopTask(tapis_fast);
			etat=0; }


		displayTextLine(1, "change_Color %d", change_Color);
		startTask(color);
		startTask(tapis);
		startTask(poussoir);



		while(change_Color){

			displayTextLine(1, "change_Color %d", change_Color);
			stopTask(color);
			wait1Msec(2000);
			stopTask(tapis_low);
			startTask(tapis_fast);
			change_Color = 0;
			etat = 2;
		}


	}
}
