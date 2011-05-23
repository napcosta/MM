#include <math.h>
#include "HUD.h"
#include "Car.h"
#include "PlayerManager.h"


namespace Micromachines {

	HUD::HUD() : cg::Entity("HUD")
	{
	}

	HUD::~HUD()
	{
	}
	
	void HUD::init()
	{
		_pm = (PlayerManager*) cg::Registry::instance()->get("PlayerManager");
		cg::tWindow win = cg::Manager::instance()->getApp()->getWindow();
		_winWidth = win.width;
		_winHeight = win.height;
		_car = NULL;
		_nitroRadius = 7;
	}
	
	void HUD::drawLifeBar()
	{
		int life = _car->getLife()/10;
		int i, oneLife = (_max-10)/10;
		int inc = oneLife;
		
		glLineWidth(0);
		glColor3d(0.4, 1, 0.1);
		for (i = 0; i < life; i++, inc+= oneLife) {
			glBegin(GL_QUADS);
			glVertex2d(_winWidth-inc, _winHeight-10);
			glVertex2d(_winWidth-inc, _winHeight-30);
			glVertex2d(_winWidth-(inc+oneLife), _winHeight-30);
			glVertex2d(_winWidth-(inc+oneLife), _winHeight-10);
			glEnd();
		}
		
		/*********** CONTORNO DA LIFEBAR ***********/
		glLineWidth(2);
		glColor3d(0, 0, 0);
		glBegin(GL_LINES);
		glVertex2d(_winWidth-10, _winHeight-10);
		glVertex2d(_winWidth-10, _winHeight-30);
		
		glVertex2d(_winWidth-10, _winHeight-30);
		glVertex2d(_winWidth-_max, _winHeight-30);
		
		glVertex2d(_winWidth-_max, _winHeight-30);
		glVertex2d(_winWidth-_max, _winHeight-10);
		
		glVertex2d(_winWidth-_max, _winHeight-10);
		glVertex2d(_winWidth-10, _winHeight-10);
		glEnd();
		/********************************************/
		
		if (_pm->hasTwoPlayers()) {
			int life = _pm->secondPlayer()->getLife()/10;
			int max = (_pm->secondPlayer()->getLife()+10);
			int i, oneLife = (max-10)/10;
			int inc = oneLife;
			
			glLineWidth(0);
			glColor3d(0.4, 1, 0.1);
			for (i = 0; i < life; i++, inc+= oneLife) {
				glBegin(GL_QUADS);
				glVertex2d(_winWidth-inc, _winHeight-100);
				glVertex2d(_winWidth-inc, _winHeight-120);
				glVertex2d(_winWidth-(inc+oneLife), _winHeight-120);
				glVertex2d(_winWidth-(inc+oneLife), _winHeight-100);
				glEnd();
			}
			
			/*********** CONTORNO DA LIFEBAR ***********/
			glLineWidth(2);
			glColor3d(0, 0, 0);
			glBegin(GL_LINES);
			glVertex2d(_winWidth-10, _winHeight-100);
			glVertex2d(_winWidth-10, _winHeight-120);
			
			glVertex2d(_winWidth-10, _winHeight-120);
			glVertex2d(_winWidth-_max, _winHeight-120);
			
			glVertex2d(_winWidth-_max, _winHeight-120);
			glVertex2d(_winWidth-_max, _winHeight-100);
			
			glVertex2d(_winWidth-_max, _winHeight-100);
			glVertex2d(_winWidth-10, _winHeight-100);
			glEnd();
			/********************************************/
		}
	}
	
	void HUD::drawNitro()
	{
		int x = _winWidth-17;
		int y = _winHeight-50;
		int carNitro = _car->getPowerUp();
		
		for (int i = 0; i < carNitro; i++) {
			
			glColor3d(0.1, 0.3, 0.2);
			glBegin(GL_TRIANGLE_FAN);
			for (int angle = 0; angle <= 360; angle = angle+5) {
				glVertex2d(x + sin(angle) * _nitroRadius, y + cos(angle) * _nitroRadius);
			}
			glEnd();
			x = x - 20;
		}
		
		x = _winWidth-17;
		
		for (int i = 0; i < 3; i++) {
			
			glLineWidth(2);
			glColor3d(0, 0, 0);
			glBegin(GL_LINE_LOOP);
			for (int angle = 0; angle <= 360; angle = angle+5) {
				glVertex2d(x + sin(angle) * _nitroRadius, y + cos(angle) * _nitroRadius);
			}
			glEnd();
			x = x - 20;
		}
		
		if (_pm->hasTwoPlayers()) {
			int x = _winWidth-17;
			int y = _winHeight-150;
			int carNitro = _pm->secondPlayer()->getPowerUp();
			
			for (int i = 0; i < carNitro; i++) {
				
				glColor3d(0.1, 0.3, 0.2);
				glBegin(GL_TRIANGLE_FAN);
				for (int angle = 0; angle <= 360; angle = angle+5) {
					glVertex2d(x + sin(angle) * _nitroRadius, y + cos(angle) * _nitroRadius);
				}
				glEnd();
				x = x - 20;
			}
			
			x = _winWidth-17;
			
			for (int i = 0; i < 3; i++) {
				
				glLineWidth(2);
				glColor3d(0, 0, 0);
				glBegin(GL_LINE_LOOP);
				for (int angle = 0; angle <= 360; angle = angle+5) {
					glVertex2d(x + sin(angle) * _nitroRadius, y + cos(angle) * _nitroRadius);
				}
				glEnd();
				x = x - 20;
			}
		}
		
	}
	
	void HUD::drawOverlay()
	{
		if(_car == NULL){
			_car = _pm->firstPlayer();
			_max = (_car->getLife()+10);
		} else {
			std::string s = "1st";
			glColor3f(0.0f, 0.0f, 0.0f);
			glRasterPos2d(300, 450);
			
			for (int i = 0; s[i] != '\0'; i++) {
				
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
			}
			
			/********************OVERLAY ELAPSED TIME***********************/
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
			/*******************************************************************/
			
			/************************ OVERLAY SPEED ****************************/
			std::ostringstream vel;
			vel << (int) (_car->getVelocity()*1200) << " km/h";
			std::string velocity = vel.str();
			glColor3f(0.3f, 1.0f, 1.0f);
			glRasterPos2d(50, 50);
			for(int k = 0; velocity[k] != '\0'; k++)
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, velocity[k]);
			
			/*******************************************************************/
			
			drawLifeBar();
			drawNitro();
		}
	}
		

}
