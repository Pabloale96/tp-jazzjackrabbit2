#include "../../include/animaciones.h"


Animacion::~Animacion(){}

Animacion::Animacion(Renderer & render,Texture & sprites):
                        render(render),sprites(sprites){}

AnimacionDerecha::AnimacionDerecha(Renderer & render,Texture & sprites):
                        Animacion(render,sprites)
{
   
   for (size_t i = 0; i < (sizeof(x_frames)/sizeof(x_frames[0])); i++)
   {
      Frame frame(render,sprites);
      frame.setFrame(x_frames[i],y_frames[i],w_frames[i],h_frames[i]);
      frames.emplace_back(frame);
   }                   
}

AnimacionDerecha::~AnimacionDerecha(){}

void AnimacionDerecha::run(){
   frames[scr_x].copy();
   scr_x++;
   if (scr_x == 8) scr_x=0;
 }

/*
void Animacion::moverIzquierda(){
    sprites.SetAlphaMod(255);
	render.Copy(
            sprites,
            Rect(walk[scr_x], 884, 50, 47),
            Rect(render.GetOutputWidth()/2-25, render.GetOutputHeight()/2-23, 75, 75),
            180.0,
            NullOpt,
            2
    );
    scr_x++;
    if (scr_x == 8) scr_x=0;
 }

void Animacion::standing(){
   sprites.SetAlphaMod(255);
	render.Copy(
            sprites,
            Rect(stand[scr_x], 812,39, 47),
            Rect(render.GetOutputWidth()/2-19, render.GetOutputHeight()/2-23, 75, 75)
            //180.0,
            //NullOpt,
            //2
    );
    scr_x++;
    if (scr_x == 5) scr_x=0;
 }
 */