int bool_puch = 0;

task color(){

	short codeCouleur =0;
	int red = 0;
	int blue = 0;
	int green = 0;

	codeCouleur = getColorName(S1);

	getColorRawRGB(S1, red, blue, green);

	displayTextLine(1, "red %d", red);
	displayTextLine(2, "blue %d", blue);
	displayTextLine(3, "green %d", green);


	/*if(codeCouleur == 2){
			displayTextLine(4, "bleu");
			//setMotorSpeed(motorD, -30);
			//sleep(2000);
		}
		else if(codeCouleur == 4){
			displayTextLine(4, "jaune");
			//setMotorSpeed(motorD, 75);
			//sleep(2000);
		}
		else if(codeCouleur == 5){
			displayTextLine(4, "rouge");
			//setMotorSpeed(motorD, 50);
			//sleep(2000);
		}
		else if(codeCouleur == 3){
			displayTextLine(4, "vert");
			//setMotorSpeed(motorD, -30);
			//sleep(2000);
		}
		else{
			displayTextLine(4, "codeCouleur %d", codeCouleur);
		}*/
		sleep(1000);
}





task poussoir(){

	int p = getTouchValue(S3);
	displayTextLine(6, "bouton %d", p);

	//setMotorTarget(motorD, 0, 100);
	//sleep(1000);

	if(p == 1){

			moveMotor(motorA, 360, degrees, 60);
			setMotorSpeed(motorB, 20);
			resetMotorEncoder(motorA);


	}

	p = 0;
	bool_puch = 1;
}



task tapis(){

	setMotorSpeed(motorB, 30);
}

task tapis2(){

	setMotorSpeed(motorD, 20);
}


task main()
{
	SensorType[S3] = sensorEV3_Touch;
	SensorType[S1] = sensorEV3_Color;

	setSensorMode(S1, modeEV3Color_Color);

	while(1){
		startTask(poussoir);
		while(!bool_puch){
			startTask(color);
			startTask(tapis);
			startTask(tapis2);
		}
		bool_puch = 0;
		stopTask(color);
		stopTask(poussoir);
		stopTask(tapis);
		stopTask(tapis2);


		if(getButtonPress(buttonLeft) == true){
			stopMotor(motorB);
			setLEDColor(ledOrange);
			playTone(310);
			sleep(100);
			clearSounds();
			setLEDColor(ledGreen);
		}
		if(getButtonPress(buttonRight) == true){
			stopMotor(motorD);
			sleep(1000);
		}
	}

}
