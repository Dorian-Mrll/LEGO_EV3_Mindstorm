int bool_puch = 0;


task color(){

	//short codeCouleur =0;
	int red = 0;
	int blue = 0;
	int green = 0;
	//codeCouleur = getColorName(S1);

	long redChannel; long greenChannel; long blueChannel;

	getColorRawRGB(S1, red, blue, green);

	/*displayTextLine(1, "red %d", red);
	displayTextLine(2, "green %d", green);
	displayTextLine(3, "blue %d", blue);*/


	getColorRGB(S1, blueChannel, redChannel, greenChannel);
	displayTextLine(1, "red %d", redChannel);
	displayTextLine(2, "green %d", greenChannel);
	displayTextLine(3, "blue %d", blueChannel);

	int amb = getColorHue(S1);
	displayTextLine(5, "hue %d", amb);
	int sat = getColorSaturation(S1);
	displayTextLine(6, "saturation %d", sat);
	int ref = getColorReflected(S1);
	displayTextLine(7, "reflect %d", ref);

	if(sat == 100){

		if((redChannel>=1 && redChannel<=2) && (greenChannel>=3 && greenChannel<=6) && (blueChannel <= 1))
			displayTextLine(4, "bleu");

		else if((redChannel>=1 && redChannel<=2) && (greenChannel>=1) && (blueChannel <= 1))
			displayTextLine(4, "vert");
	}



	/*if(codeCouleur == 2){
			displayTextLine(4, "bleu");
		}
		else if(codeCouleur == 4){
			displayTextLine(4, "jaune");
		}
		else if(codeCouleur == 5){
			displayTextLine(4, "rouge");
		}
		else if(codeCouleur == 3){
			displayTextLine(4, "vert");
		}
		else{
			displayTextLine(4, "codeCouleur %d", codeCouleur);
		}*/
}





/*task poussoir(){

	int p = getTouchValue(S3);
	displayTextLine(6, "bouton %d", p);

	//setMotorTarget(motorD, 0, 100);
	//sleep(1000);

	if(p == 1){

			moveMotor(motorD, 360, degrees, 60);
			setMotorSpeed(motorA, 20);
			resetMotorEncoder(motorD);
	}

	p = 0;
	bool_puch = 1;
}*/



/*task tapis(){

	setMotorSpeed(motorA, 50);
}*/



task main()
{
	//SensorType[S3] = sensorEV3_Touch;
	SensorType[S1] = sensorEV3_Color;
	setSensorMode(S1, modeEV3Color_Color);

	while(1){
		//startTask(poussoir);
		//while(!bool_puch){
			startTask(color);
			//startTask(tapis);
		//}
		//bool_puch = 0;
		sleep(1000);
		stopTask(color);
		//stopTask(poussoir);
		//stopTask(tapis);
	}

}
