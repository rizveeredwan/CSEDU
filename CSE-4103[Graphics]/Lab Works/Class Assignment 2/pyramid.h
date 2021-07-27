void pyramid(void) {
	glBegin(GL_TRIANGLES);
	// front
	glColor3f(OGVIOLET);
	glVertex3f(0.0,1.0,0.0);
	glVertex3f(-1.0,-1.0,1.0);
	glVertex3f(1.0,-1.0,1.0);
	
	// right
	glColor3f(OGBLUE);
	glVertex3f(0.0,1.0,0.0);
	glVertex3f(1.0,-1.0,1.0);
	glVertex3f(1.0,-1.0,-1.0);
	
	// back
	glColor3f(OGORANGE);
	glVertex3f(0.0,1.0,0.0);
	glVertex3f(1.0,-1.0,-1.0);
	glVertex3f(-1.0,-1.0,-1.0);
	
	// left
	glColor3f(OGRED);
	glVertex3f(0.0,1.0,0.0);
	glVertex3f(-1.0,-1.0,-1.0);
	glVertex3f(-1.0,-1.0,1.0);
	
	/*
	// bottom
	glBegin(GL_QUADS);
	glColor3f(OGCYAN);
	glVertex3f(1.0,-1.0,1.0);
	glVertex3f(1.0,-1.0,-1.0);
	glVertex3f(-1.0,-1.0,-1.0);
	glVertex3f(-1.0,-1.0,1.0);
	*/
	
	glEnd();
}
