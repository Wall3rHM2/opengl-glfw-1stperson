#pragma once
void DrawTriangle(float size)
{
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 0, 0);
    glVertex2f(0, size);
    glColor3ub(0, 255, 0);
    glVertex2f(-size, 0.f);
    glColor3ub(0, 0, 255);
    glVertex2f(size, 0.f);
    glEnd();
}

void DrawPyramid(float size)
{
    glBegin(GL_TRIANGLES);

    glColor3ub(255, 255, 0);
    glVertex3f(0, size, 0);
    glColor3ub(0, 255, 255);
    glVertex3f(-size / 2, 0.f, size / 2.f);
    glColor3ub(255, 0, 255);
    glVertex3f(size / 2, 0.f, size / 2.f);

    glColor3ub(0, 255, 0);
    glVertex3f(0, size, 0);
    glColor3ub(255, 0, 0);
    glVertex3f(-size / 2, 0.f, -size / 2.f);
    glColor3ub(0, 0, 255);
    glVertex3f(size / 2, 0.f, -size / 2.f);


    glColor3ub(0, 0, 255);
    glVertex3f(0, size, 0);
    glColor3ub(0, 255, 0);
    glVertex3f(size / 2, 0.f, -size / 2.f);
    glColor3ub(255, 0, 0);
    glVertex3f(size / 2, 0.f, size / 2.f);

    glColor3ub(0, 255, 255);
    glVertex3f(0, size, 0);
    glColor3ub(255, 0, 0);
    glVertex3f(-size / 2, 0.f, -size / 2.f);
    glColor3ub(255, 255, 0);
    glVertex3f(-size / 2, 0.f, size / 2.f);

    //base of pyramid (square/rectangle)

    glColor3ub(0, 255, 255);
    glVertex3f(size / 2, 0, -size / 2);
    glColor3ub(255, 0, 0);
    glVertex3f(-size / 2, 0.f, size / 2.f);
    glColor3ub(255, 255, 0);
    glVertex3f(size / 2, 0.f, size / 2.f);

    glColor3ub(255, 255, 0);
    glVertex3f(size / 2, 0, -size / 2);
    glColor3ub(0, 255, 0);
    glVertex3f(-size / 2, 0.f, -size / 2.f);
    glColor3ub(0, 255, 255);
    glVertex3f(-size / 2, 0.f, size / 2.f);


    glEnd();
}

void DrawPly(float size, int r, int g, int b) {
    float w = size / 2;
    glBegin(GL_LINES);

    glColor3ub(r, g, b);
    //base
    glVertex3f(-w, -size, -w);
    glVertex3f(w, -size, -w);

    glVertex3f(w, -size, -w);
    glVertex3f(w, -size, w);

    glVertex3f(w, -size, w);
    glVertex3f(-w, -size, w);

    glVertex3f(-w, -size, w);
    glVertex3f(-w, -size, -w);

    //height
    glVertex3f(-w, -size, -w);
    glVertex3f(-w, size, -w);

    glVertex3f(w, -size, -w);
    glVertex3f(w, size, -w);

    glVertex3f(w, -size, w);
    glVertex3f(w, size, w);

    glVertex3f(-w, -size, w);
    glVertex3f(-w, size, w);

    //top
    glVertex3f(-w, size, -w);
    glVertex3f(w, size, -w);

    glVertex3f(w, size, -w);
    glVertex3f(w, size, w);

    glVertex3f(w, size, w);
    glVertex3f(-w, size, w);

    glVertex3f(-w, size, w);
    glVertex3f(-w, size, -w);

    glEnd();
}