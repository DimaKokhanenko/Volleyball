#include "alfacl.hpp"

int main()
{
    if(!glfwInit())
    {
        cout << "GLFW not found\n";
        glfwTerminate();
        return -1;
    }
    
    glewExperimental = true;
    
    GLFWwindow* window = glfwCreateWindow(1000, 650, "Ball game", NULL, NULL);
    glfwMakeContextCurrent(window);
    
    node player1;
    node player2;
    node prball;
    node grid;
    node map;
    player_move pl1mv;
    player_move pl2mv;
    ball_physics ball;
    windowset setting(window);
    
    glfwSetKeyCallback(window, setting.escfnc);
    
    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        
        map.prsky();
        map.prwater();
        map.prsand();
        
        glPushMatrix();
        glTranslatef(pl1mv.fpo, -0.65, 0);
        
        player1.prcl(30, 0.5, 1, 1, 0.3, 0.3);
        
        glPopMatrix();
        
        glPushMatrix();
        glTranslatef(pl2mv.spo, -0.65, 0);
        
        player2.prcl(30, 1, 0.5, 0.5, 0.3, 0.3);
        
        glPopMatrix();
        
        grid.prgi(0.5, 0.5, 1);
        
        glPushMatrix();
        glTranslatef(ball.ballx, ball.bally, 0);
//        -0.65
        
        prball.prcl(30, 1, 0.6, 1, 0.23, 0.23);
        
        glPopMatrix();
        
        glfwSwapBuffers(window);
        
        if(glfwGetKey(window, GLFW_KEY_A))
            pl1mv.movepl1lf();
        
        if(glfwGetKey(window, GLFW_KEY_D))
            pl1mv.movepl1rg();
        
        if(glfwGetKey(window, GLFW_KEY_LEFT))
            pl2mv.movepl2lf();
        
        if(glfwGetKey(window, GLFW_KEY_RIGHT))
            pl2mv.movepl2rg();
        
        ball.allphysic(pl1mv, pl2mv, window);
    }
    
    return 0;
}
