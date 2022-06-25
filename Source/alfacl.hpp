// HEADER FILE
// alfacl.hpp

#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>
using namespace std;

class windowset
{
public:
    windowset(GLFWwindow* window);
    ~windowset();
    static void escfnc(GLFWwindow* window, int key, int scancode, int action, int mods);
    
private:
    float scrW = 1000;
    float scrH = 650;
    float kf;
    GLFWwindow* window;
    
};

struct node
{
    void prcl(int cmk, float rd, float gr, float bl, float scalex, float scaley);
    void prgi(float rd, float gr, float bl);
    void prsky();
    void prwater();
    void prsand();
    
};

class ball_physics;

class player_move
{
public:
    void movepl1lf();
    void movepl1rg();
    void movepl2lf();
    void movepl2rg();
    
private:
    float fpo = -0.75f;;
    float spo = 0.75f;;
    
    friend int main();
    friend ball_physics;
};

class ball_physics
{
public:
    void allphysic(player_move &player1, player_move &player2, GLFWwindow* window);
    void godownfn();
    void gran();
    void bplphs(player_move &player1, player_move &player2, GLFWwindow* window);
    
private:
    float ballx = -0.65f;
    float bally = 0;
    float toxsp = 0.03f;
    float gravity = 0.02f;
    float twgr = 0.0f;
    bool godown = true;
    bool b1side = false;
    bool b2side = false;
    
    friend int main();
};
