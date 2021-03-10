// The sample model.  You should build a file
// very similar to this for when you make your model.
#include "modelerview.h"
#include "modelerapp.h"
#include "modelerdraw.h"
#include <FL/gl.h>

#include "modelerglobals.h"

// To make a SampleModel, we inherit off of ModelerView
class SampleModel : public ModelerView 
{
public:
    SampleModel(int x, int y, int w, int h, char *label) 
        : ModelerView(x,y,w,h,label) { }

    virtual void draw();
};

// We need to make a creator function, mostly because of
// nasty API stuff that we'd rather stay away from.
ModelerView* createSampleModel(int x, int y, int w, int h, char *label)
{ 
    return new SampleModel(x,y,w,h,label); 
}

// We are going to override (is that the right word?) the draw()
// method of ModelerView to draw out SampleModel
void SampleModel::draw()
{
    // This call takes care of a lot of the nasty projection 
    // matrix stuff.  Unless you want to fudge directly with the 
	// projection matrix, don't bother with this ...
    ModelerView::draw();

	// draw the floor
	/*setAmbientColor(.1f,.1f,.1f);
	setDiffuseColor(COLOR_BLUE);
	glPushMatrix();
	glTranslated(-5,0,-5);
	drawBox(10,0.01f,10);
	glPopMatrix();
	*/
	

	// draw the sample model
	glPushMatrix();
	glTranslated(VAL(XPOS), VAL(YPOS), VAL(ZPOS));

		//upper torso
		glPushMatrix();
		setAmbientColor(.1f,.1f,.1f);
		setDiffuseColor(COLOR_YELLOW);
			//middle torso
			glTranslated(-1.5, 1, -2);
			glScaled(2, 1, 0.5);
			drawBox(1, VAL(HEIGHT), 1);
			//end of middle torso
			glTranslated(0,VAL(HEIGHT), 0);
			drawBox(1,1.5,1);

			//left arm
			glPushMatrix();
			glTranslated(-0.05, -0.5, 0.5);
			glScaled(1, 2, 2);
			glRotated(VAL(ROTATE), 1.0, 0.0, 0.0);
			glRotated(90, 1.0, 0.0, 0.0);
			drawCylinder(0.5, 0.1, 0.1);
			glPopMatrix();
			//end of left arm

			//right arm
			glPushMatrix();
			glTranslated(1.05, -0.5, 0.5);
			glScaled(1, 2, 2);
			glRotated(VAL(ROTATE), 1.0, 0.0, 0.0);
			glRotated(90, 1.0, 0.0, 0.0);
			drawCylinder(0.5, 0.1, 0.1);
			glPopMatrix();
			//end of right arm

			//Snail
			glPushMatrix();
			setAmbientColor(.1f, .1f, .1f);
			setDiffuseColor(COLOR_RED);
			glTranslated(0.5,2, 0.25);
			glScaled(0.5, 1, 1);
			drawSphere(0.5);
			glPopMatrix();
			//end of Snail
		
			//left eye
			glPushMatrix();
			setAmbientColor(.1f, .1f, .1f);
			setDiffuseColor(COLOR_WHITE);
			glTranslated(0.3,0.5,0.6);
			glScaled(1, 2, 2);
			drawSphere(0.25);
				//left eyeball
				glPushMatrix();
				setAmbientColor(.1f, .1f, .1f);
				setDiffuseColor(COLOR_BLACK);
				glTranslated(0, 0, 0.3);
				drawSphere(0.05);
				glPopMatrix();
				//end of left eyeball
			glPopMatrix();
			//end of left eye

			//right eye
			glPushMatrix();
			setAmbientColor(.1f, .1f, .1f);
			setDiffuseColor(COLOR_WHITE);
			glTranslated(0.7, 0.5, 0.6);
			glScaled(1, 2, 2);
			drawSphere(0.25);
				//right eyeball
				glPushMatrix();
				setAmbientColor(.1f, .1f, .1f);
				setDiffuseColor(COLOR_BLACK);
				glTranslated(0, 0, 0.3);
				drawSphere(0.05);
				glPopMatrix();
			//end of right eyeball
			glPopMatrix();
			//end of right eye

		

		glPopMatrix();
		//end of upper torso


		//lower torso
		glPushMatrix();
		setAmbientColor(.1f, .1f, .1f);
		setDiffuseColor(COLOR_BROWN);
		glTranslated(-1.5, 0,-2 );
		glScaled(2, 1, 0.5);
		drawBox(1 ,1, 1);
		//left leg
		glPushMatrix();
		glTranslated(0.25, 0, 0.25);
		glRotated(VAL(ROTATE), 1.0, 0.0, 0.0);
		glRotated(90, 1.0, 0.0, 0.0);
		drawCylinder(1,0.1,0.1);
		glPopMatrix();
		//end of left leg
		//right leg
		glPushMatrix();
		glTranslated(0.75, 0, 0.25);
		glRotated(VAL(ROTATE), 1.0, 0.0, 0.0);
		glRotated(90, 1.0, 0.0, 0.0);
		drawCylinder(1, 0.1, 0.1);
		glPopMatrix();
		//end of right leg
		glPopMatrix();
		//end of lower torso



		//downward torse
		//glTranslated(0.0, 0.0, VAL(HEIGHT));
		//drawBox(VAL(HEIGHT), 4.0, 0.1);
		//glPopMatrix();
		
		/*
		* // draw cannon
		glPushMatrix();
		glRotated(VAL(ROTATE), 0.0, 1.0, 0.0);
		glRotated(-90, 1.0, 0.0, 0.0);
		drawCylinder(VAL(HEIGHT), 0.1, 0.1);

		glTranslated(0.0, 0.0, VAL(HEIGHT));
		drawCylinder(1, 1.0, 0.9);

		glTranslated(0.0, 0.0, 0.5);
		glRotated(90, 1.0, 0.0, 0.0);
		drawCylinder(4, 0.1, 0.2);
		glPopMatrix();
		*/

	glPopMatrix();

}

int main()
{
	// Initialize the controls
	// Constructor is ModelerControl(name, minimumvalue, maximumvalue, 
	// stepsize, defaultvalue)
    ModelerControl controls[NUMCONTROLS];
    controls[XPOS] = ModelerControl("X Position", -5, 5, 0.1f, 0);
    controls[YPOS] = ModelerControl("Y Position", 0, 5, 0.1f, 0);
    controls[ZPOS] = ModelerControl("Z Position", -5, 5, 0.1f, 0);
    controls[HEIGHT] = ModelerControl("Height", 1, 2.5, 0.1f, 1);
	controls[ROTATE] = ModelerControl("Rotate", -135, 135, 1, 0);

    ModelerApplication::Instance()->Init(&createSampleModel, controls, NUMCONTROLS);
    return ModelerApplication::Instance()->Run();
}
