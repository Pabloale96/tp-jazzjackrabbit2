#include "../../include/client_src/gui/gui_audio.h"

Audio::Audio(Mixer& mixer, std::string audio ):
    mixer(mixer),
    audio(audio){}

Audio::~Audio(){}
void Audio::run(){
    int reproducir = mixer.GetGroupAvailableChannel(0);
    if(reproducir){
        mixer.PlayChannel(disponible, sonido, 0);
    }
}