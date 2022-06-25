// UNDER HEADER FILE
// alfacl.cpp

#include "alfacl.hpp"

windowset::windowset(GLFWwindow* window)
{
    kf = (float)scrW / scrH;
    glScalef(1/kf, 1, 1);
    this->window = window;
}

windowset::~windowset()
{
    glfwDestroyWindow(window);
}

void windowset::escfnc(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void node::prcl(int cmk, float rd, float gr, float bl, float scalex, float scaley)
{
    float x;
    float y;
    float db = M_PI * 2.0 / cmk;
    
    glPushMatrix();
    
    glScalef(scalex, scaley, 1);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(rd, gr, bl);
    glVertex2f(0, 0);
    for(int i = 0; i <= cmk; i++)
    {
        x = sin(db * i);
        y = cos(db * i);
        glVertex2f(x, y);
    }
    
    glEnd();
    
    glPopMatrix();
}

void node::prgi(float rd, float gr, float bl)
{
    glLineWidth(15);
    
    glPushMatrix();
    
    glBegin(GL_LINE_STRIP);
    glColor3f(rd, gr, bl);
    glVertex2f(-0.05, -1);
    glVertex2f(-0.05, -0.15);
    glVertex2f(0.05, -0.15);
    glVertex2f(0.05, -1);
    
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(rd, gr, bl);
    glVertex2f(-0.05, -0.2);
    glVertex2f(0.05, -0.3);
    glVertex2f(-0.05, -0.3);
    glVertex2f(0.05, -0.4);
    glVertex2f(-0.05, -0.4);
    glVertex2f(0.05, -0.5);
    glVertex2f(-0.05, -0.5);
    glVertex2f(0.05, -0.6);
    glVertex2f(-0.05, -0.6);
    glVertex2f(0.05, -0.7);
    
    glEnd();
    
    glPopMatrix();
}

void node::prsky()
{
    glPushMatrix();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.4, 0.6, 1);
    glVertex2f(-1.55, 1);
    glVertex2f(1.55, 1);
    glVertex2f(1.55, 0.45);
    glVertex2f(-1.55, 0.45);
    
    glEnd();
    
    glPopMatrix();
}

// glColor3f(0.2, 0.3, 1);

void node::prwater()
{
    glPushMatrix();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.2, 0.3, 1);
    glVertex2f(-1.55, 0.45);
    glVertex2f(1.55, 0.45);
    glVertex2f(1.55, 0);
    glVertex2f(-1.55, 0);
    
    glEnd();
    
    glPopMatrix();
}

void node::prsand()
{
    glPushMatrix();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.8, 0.6, 0);
    glVertex2f(-1.55, 0);
    glVertex2f(1.55, 0);
    glVertex2f(1.55, -1);
    glVertex2f(-1.55, -1);
    
    glEnd();
    
    glPopMatrix();
}

void player_move::movepl1lf()
{
    if(fpo < -1.2f)
        fpo += 0;
    else
        fpo += -0.01f;
}

void player_move::movepl1rg()
{
    if(fpo > -0.36f)
        fpo += 0;
    else
        fpo += 0.01f;
}

void player_move::movepl2lf()
{
    if(spo < 0.36f)
        spo += 0;
    else
        spo += -0.01f;
}

void player_move::movepl2rg()
{
    if(spo > 1.2f)
        spo += 0;
    else
        spo += 0.01f;
}

void ball_physics::godownfn()
{
    if(twgr < -1)
    {
        godown = false;
    }
    
    bally -= gravity;
    
    if(bally >= twgr)
        gravity = 0.015f;
    
    if(bally <= -0.65f)
    {
        gravity = -0.012f;
        twgr -= 0.15f;
    }
}

void ball_physics::gran()
{
    if(ballx < -1.25f)
        b1side = true;
    
    if(ballx > 1.25f)
        b2side = true;
    
    cout << ballx << endl;
    if(ballx < 0.06f && ballx > 0.02f && bally < -0.32f)
    {
        b2side = true;
        ballx -= 0.06f;
    }
    
    if(ballx < 0.16f && ballx > 0.10f && bally < -0.32f)
    {
        b1side = true;
        ballx += 0.06f;
    }
    
}

void ball_physics::bplphs(player_move &player1, player_move &player2, GLFWwindow* window)
{
    ballx += toxsp;
    
    if(toxsp > 0)
        toxsp -= 0.0002f;
    if(toxsp < 0)
        toxsp += 0.0002f;
    
    if(b1side == true)
    {
        toxsp *= -1;
        ballx += 0.06f;
        b1side = false;
    }
    
    if(b2side == true)
    {
        b2side = false;
        ballx -= 0.06f;
        toxsp *= -1;
    }
    cout << toxsp << endl;
}

void ball_physics::allphysic(player_move &player1, player_move &player2, GLFWwindow *window)
{
    if(godown == true)
        godownfn();
    
    gran();
    
    bplphs(player1, player2, window);
    
    if(glfwGetKey(window, GLFW_KEY_P))
    {
        toxsp = 0.03f;
        godown = true;
        twgr = 0;
    }
    
    if(player1.fpo - 0.05f < ballx && player1.fpo > ballx && bally < -0.35f)
    {
        toxsp = 0.03f;
        godown = true;
        twgr = 0;
    }
    
    if(player2.spo + 0.05f > ballx && player2.spo < ballx && bally < -0.35f)
    {
        toxsp = -0.03f;
        godown = true;
        twgr = 0;
    }
}

