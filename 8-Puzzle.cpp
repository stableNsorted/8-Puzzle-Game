
    #include <GL/glut.h>
    #include <bits/stdc++.h>
    #include <GL/freeglut.h>

    using namespace std;

    int window_width = 1350, window_height = 690;
    int boxes[9][4] = {{450,600,420,570}, {600,750,420,570}, {750,900,420,570},
                        {450,600,270,420}, {600,750,270,420}, {750,900,270,420},
                        {450,600,120,270}, {600,750,120,270}, {750,900,120,270}};
    float color_box[9][3] = {{0.2f, 0.4f, 0.7f}, {0.2f, 0.4f, 0.7f}, {0.2f, 0.4f, 0.7f},
                            {0.2f, 0.4f, 0.7f}, {0.2f, 0.4f, 0.7f}, {0.2f, 0.4f, 0.7f},
                            {0.2f, 0.4f, 0.7f}, {0.2f, 0.4f, 0.7f}, {0.2f, 0.4f, 0.7f}};
    bool game_finished = false;
    char moves[3][3] = {{'2', '8', '1'},
                        {' ', '4', '3'},
                        {'7', '6', '5'}};
    int restart_x1 = 1050, restart_x2 = 1200, restart_y1 = 320, restart_y2 = 380;
    float restart_red = 0.7f, restart_green = 0.2f, restart_blue = 0.2f;
    void initGL()
    {
        glClearColor(0.2f, 0.5f, 0.1f, 1.0);
        glMatrixMode(GL_PROJECTION);
        gluOrtho2D(0, window_width, 0, window_height);
    }

    void drawString(float x, float y, float z, char * str, float r, float g, float b)
    {
        glColor3f(r, g, b);
        glRasterPos3f(x, y, z);
        for (char* c = str; *c != '\0';c++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }

    void drawStrokeText(float x, float y, float z, char* str, float r, float g, float b, float scalex, float scaley, float scalez)
    {
          glColor3f(r, g, b);
          glPushMatrix();
          glTranslatef(x, y, z);
          glScalef(scalex, scaley, scaley);
          for (char *c= str; *c != '\0'; c++)
                glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN  , *c);
          glPopMatrix();
    }

    void passive_motion(int x, int y)
    {
        y = window_height - y;
        for(int i = 0; i < 9; i++)
        {
            if(x >= boxes[i][0] && x <= boxes[i][1] && y >= boxes[i][2] && y <= boxes[i][3])
            {
                color_box[i][0] = 0.3f;
                color_box[i][1] = 0.4f;
                color_box[i][2] = 0.7f;
                glutPostRedisplay();
            }
            else
            {
                color_box[i][0] = 0.7f;
                color_box[i][1] = 0.5f;
                color_box[i][2] = 0.3f;
                glutPostRedisplay();
            }
        }
        if(x >= restart_x1 && x <= restart_x2 && y >= restart_y1 && y <= restart_y2)
        {
            restart_red = 0.8f;
            restart_green = 0.3f;
            restart_blue = 0.5f;
            restart_x1 = 1045;
            restart_x2 = 1205;
            restart_y1 = 315;
            restart_y2 = 385;
            glutPostRedisplay();
        }
        else
        {
            restart_red = 0.7f;
            restart_green = 0.2f;
            restart_blue = 0.2f;
            restart_x1 = 1050;
            restart_x2 = 1200;
            restart_y1 = 320;
            restart_y2 = 380;
            glutPostRedisplay();
        }
    }

    void mouse(int button, int state, int x, int y)
    {
        y = window_height - y;
        if(!game_finished && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            for(int i = 0; i < 9; i++)
            {
                if(x >= boxes[i][0] && x <= boxes[i][1] && y >= boxes[i][2] && y <= boxes[i][3])
                {
                    // First Row
                    if(i/3 == 0)
                    {
                        if(i%3 == 0)
                        {
                            if(moves[0][1] == ' ')
                            {
                                swap(moves[i/3][i%3], moves[0][1]);
                            }
                            if(moves[1][0] == ' ')
                            {
                                swap(moves[i/3][i%3], moves[1][0]);
                            }
                        }
                        if(i%3 == 1)
                        {
                            if(moves[0][0] == ' ')
                            {
                                swap(moves[i/3][i%3], moves[0][0]);
                            }
                            if(moves[0][2] == ' ')
                            {
                                swap(moves[i/3][i%3], moves[0][2]);
                            }
                            if(moves[1][1] == ' ')
                            {
                                swap(moves[i/3][i%3], moves[1][1]);
                            }
                        }
                        if(i%3 == 2)
                        {
                            if(moves[0][1] == ' ')
                            {
                                swap(moves[i/3][i%3], moves[0][1]);
                            }
                            if(moves[1][2] == ' ')
                            {
                                swap(moves[i/3][i%3], moves[1][2]);
                            }
                        }
                    }
                    // Second Row
                    if(i/3 == 1)
                    {
                        if(i%3 == 0)
                        {
                            if(moves[0][0] == ' ')
                            {
                                swap(moves[i/3][i%3], moves[0][0]);
                            }
                            if(moves[1][1] == ' ')
                            {
                                swap(moves[i/3][i%3], moves[1][1]);
                            }
                            if(moves[2][0] == ' ')
                            {
                                swap(moves[i/3][i%3], moves[2][0]);
                            }
                        }
                        if(i%3 == 1)
                        {
                            if(moves[0][1] == ' ')
                            {
                                swap(moves[i/3][i%3], moves[0][1]);
                            }
                            if(moves[1][0] == ' ')
                            {
                                swap(moves[i/3][i%3], moves[1][0]);
                            }
                            if(moves[1][2] == ' ')
                            {
                                swap(moves[i/3][i%3], moves[1][2]);
                            }
                            if(moves[2][1] == ' ')
                            {
                                swap(moves[i/3][i%3], moves[2][1]);
                            }
                        }
                        if(i%3 == 2)
                        {
                            if(moves[0][2] == ' ')
                            {
                                swap(moves[i/3][i%3], moves[0][2]);
                            }
                            if(moves[1][1] == ' ')
                            {
                                swap(moves[i/3][i%3], moves[1][1]);
                            }
                            if(moves[2][2] == ' ')
                            {
                                swap(moves[i/3][i%3], moves[2][2]);
                            }
                        }
                    }
                    // Third Row
                    if(i/3 == 2)
                    {
                        if(i%3 == 0)
                        {
                            if(moves[1][0] == ' ')
                            {
                                swap(moves[i/3][i%3], moves[1][0]);
                            }
                            if(moves[2][1] == ' ')
                            {
                                swap(moves[i/3][i%3], moves[2][1]);
                            }
                        }
                        if(i%3 == 1)
                        {
                            if(moves[1][1] == ' ')
                            {
                                swap(moves[i/3][i%3], moves[1][1]);
                            }
                            if(moves[2][0] == ' ')
                            {
                                swap(moves[i/3][i%3], moves[2][0]);
                            }
                            if(moves[2][2] == ' ')
                            {
                                swap(moves[i/3][i%3], moves[2][2]);
                            }
                        }
                        if(i%3 == 2)
                        {
                            if(moves[1][2] == ' ')
                            {
                                swap(moves[i/3][i%3], moves[1][2]);
                            }
                            if(moves[2][1] == ' ')
                            {
                                swap(moves[i/3][i%3], moves[2][1]);
                            }
                        }
                    }

                }
                glutPostRedisplay();
            }
        }
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && x >= restart_x1 && x <= restart_x2 && y >= restart_y1 && y <= restart_y2)
        {
            moves[0][0] = '2'; moves[0][1] = '8'; moves[0][2] = '1';
            moves[1][0] = ' '; moves[1][1] = '4'; moves[1][2] = '3';
            moves[2][0] = '7'; moves[2][1] = '6'; moves[2][2] = '5';
            game_finished = false;
            glutPostRedisplay();
        }
    }

    void display()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        drawStrokeText(435, 600, 0, "8 Puzzle Game", 1.0f, 1.0f, 1.0f, 0.4f,0.4f, 1.0f);
        drawStrokeText(50, 580, 0, "  GOAL ", 0.0f, 0.0f, 0.0f, 0.3f,0.3f, 1.0f);
        drawStrokeText(50, 530, 0, " 1 2 3 ", 0.0f, 0.0f, 0.0f, 0.3f,0.3f, 1.0f);
        drawStrokeText(50, 485, 0, " 8   4 ", 0.0f, 0.0f, 0.0f, 0.3f,0.3f, 1.0f);
        drawStrokeText(50, 440, 0, " 7 6 5 ", 0.0f, 0.0f, 0.0f, 0.3f,0.3f, 1.0f);
        int k;
        for(k = 0; k < 9; k++)
        {
            glColor3f(color_box[k][0], color_box[k][1], color_box[k][2]);
            glBegin(GL_POLYGON);
                glVertex2i(boxes[k][0], boxes[k][3]);
                glVertex2i(boxes[k][0], boxes[k][2]);
                glVertex2i(boxes[k][1], boxes[k][2]);
                glVertex2i(boxes[k][1], boxes[k][3]);
            glEnd();
        }
        glLineWidth(2);
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_LINES);
            glVertex2i(boxes[0][0], boxes[0][3]);
            glVertex2i(boxes[0][0], boxes[7][2]);

            glVertex2i(boxes[0][0], boxes[7][2]);
            glVertex2i(boxes[2][1], boxes[7][2]);

            glVertex2i(boxes[2][1], boxes[7][2]);
            glVertex2i(boxes[2][1], boxes[0][3]);

            glVertex2i(boxes[2][1], boxes[0][3]);
            glVertex2i(boxes[0][0], boxes[0][3]);

            glVertex2i(boxes[0][0] + (boxes[2][1]-boxes[0][0])/3, boxes[0][3]);
            glVertex2i(boxes[0][0] + (boxes[2][1]-boxes[0][0])/3, boxes[7][2]);

            glVertex2i(boxes[0][0] + 2*(boxes[2][1]-boxes[0][0])/3, boxes[0][3]);
            glVertex2i(boxes[0][0] + 2*(boxes[2][1]-boxes[0][0])/3, boxes[7][2]);

            glVertex2i(boxes[0][0], boxes[7][2] + (boxes[0][3]-boxes[7][2])/3);
            glVertex2i(boxes[2][1], boxes[7][2] + (boxes[0][3]-boxes[7][2])/3);

            glVertex2i(boxes[0][0], boxes[7][2] + 2*(boxes[0][3]-boxes[7][2])/3);
            glVertex2i(boxes[2][1], boxes[7][2] + 2*(boxes[0][3]-boxes[7][2])/3);
        glEnd();

        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
            {
                string t(1, moves[i][j]);
                char temp[1];
                strcpy(temp, t.c_str());
                drawStrokeText(boxes[0][0]+50 + j*150, (boxes[0][3]-100) - i*150, 0, temp, 1.0f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f);
            }
        if(moves[0][0] == '1' && moves[0][1] == '2' && moves[0][2] == '3' && moves[1][0] == '8'
           && moves[1][1] == ' ' && moves[1][2] == '4' && moves[2][0] == '7' && moves[2][1] == '6' && moves[2][2] == '5')
        {
            game_finished = true;
        }
        if(game_finished)
            drawStrokeText(470, 60, 0, "YEAH!!YOU WON", 1.0f, 1.0f, 0.0f, 0.3f, 0.3f, 0.3f);
        glColor3f(restart_red, restart_green, restart_blue);
        glBegin(GL_POLYGON);
            glVertex2i(restart_x1, restart_y2);
            glVertex2i(restart_x1, restart_y1);
            glVertex2i(restart_x2, restart_y1);
            glVertex2i(restart_x2, restart_y2);
        glEnd();
        drawString(1070, 340, 0, "RESTART", 1.0f, 1.0f, 1.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_LINES);
            glVertex2i(restart_x1, restart_y2);
            glVertex2i(restart_x1, restart_y1);

            glVertex2i(restart_x1, restart_y1);
            glVertex2i(restart_x2, restart_y1);

            glVertex2i(restart_x2, restart_y1);
            glVertex2i(restart_x2, restart_y2);

            glVertex2i(restart_x2, restart_y2);
            glVertex2i(restart_x1, restart_y2);
        glEnd();
        glFlush();
    }

    int main(int argc, char **argv)
    {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
        glutInitWindowPosition(0, 5);
        glutInitWindowSize(window_width, window_height);
        glutCreateWindow("8 Puzzle Game");
        initGL();
        glutDisplayFunc(display);
        glutPassiveMotionFunc(passive_motion);
        glutMouseFunc(mouse);
        glutMainLoop();

        return 0;
    }
