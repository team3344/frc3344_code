/*
 *  RFVisionInterpreter.h
 *  
 *
 *  Created by Justin Buchanan on 1/8/11.
 *  Copyright 2011 JustBuchanan Software. All rights reserved.
 *
 */








class RFVisionInterpreter {
	
	
	
	vector<RFVector> ScoringPegLocations();
	bool IsFresh();
	
	
	
	
	
private:
	AxisCamera camera;
	bool accessedLatest;
	
	
	
};







