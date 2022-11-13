int bool_puch = 0;

task supersonic(){

	int dist = getUSDistance(S4);

	displayTextLine(6, "dist %d", dist);
}


task main()
{
	SensorType[S4] = sensorEV3_Ultrasonic;
	setSensorMode(S4, modeEV3Ultrasonic_Cm);

	while(1){

		//startTask(poussoir);
		//startTask(tapis);
		startTask(supersonic);


		displayTextLine(2, "bool_puch %d", bool_puch);
	}

}
