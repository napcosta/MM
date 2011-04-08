#include "HUD.h"

namespace Micromachines {

	HUD::HUD() : cg::Entity("HUD")
	{
	}

	HUD::~HUD()
	{
	}
	
	void HUD::init()
	{
	}
	
	void HUD::drawOverlay()
	{
		std::string s = "1st";
		glColor3f(0.0f, 0.0f, 0.0f);
		glRasterPos2d(300, 450);
		
       		for (int i = 0; s[i] != '\0'; i++) {

        		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
        	}
        	
        	int minutes = (glutGet(GLUT_ELAPSED_TIME)/60000)%60;
        	int seconds = (glutGet(GLUT_ELAPSED_TIME)/1000)%60;
        	int tenthsecs = (glutGet(GLUT_ELAPSED_TIME)/10) % 100;
        	
        	std::ostringstream time;
        	time << minutes << " : " << seconds;
        	time <<  " : " << tenthsecs;
        	
        	std::string strtime = time.str();
        	glRasterPos2d(20, 450);
        	for (int j = 0; strtime[j] != '\0'; j++) {

        		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, strtime[j]);
        	}
	}
		

}
