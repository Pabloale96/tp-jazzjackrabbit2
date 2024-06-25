#include "../../include/client_src/gui/gui_clase_sonidos.h"

Audio& ClaseSonidos::findAudio(std::string key) {
    auto it = audios_map.find(key);
    if (it == audios_map.end()) {
        std::cout << "No se encontro los frames" << std::endl;
    }
    return it->second;
}


ClaseSonidos::ClaseSonidos(Mixer& mixer):mixer(mixer) {
    this->addAudioCastle();
    this->addAudioJump();
    this->addAudioExplosion();
    this->addAudioHit();
    this->addAudioShoot();
    this->addAudioPick();
}

ClaseSonidos::addAudio(std::string key,Audio & audio){
    frame_number.emplace(key, audio);
}

ClaseSonidos::addAudioCastle(){
    Audio audio(mixer,RUTA_AMBIENTE_CASTLE);
    this->addAudio(AMBIENTE_CASTLE,audio);
}
ClaseSonidos::addAudioJump(){
    Audio audio(mixer,RUTA_AUDIO_JUMP);
    this->addAudio(AUDIO_JUMP,audio);
}
ClaseSonidos::addAudioExplosion(){
    Audio audio(mixer,RUTA_AUDIO_EXPLOSION);
    this->addAudio(AUDIO_EXPLOSION,audio);
}
ClaseSonidos::addAudioHit(){
    Audio audio(mixer,RUTA_AUDIO_HIT);
    this->addAudio(AUDIO_HIT,audio);
}
ClaseSonidos::addAudioShoot(){
    Audio audio(mixer,RUTA_AUDIO_SHOOT);
    this->addAudio(AUDIO_SHOOT,audio);
}
ClaseSonidos::addAudioPick(){
    Audio audio(mixer,RUTA_AUDIO_PICK);
    this->addAudio(AUDIO_PICK,audio);
}

ClaseSonidos::~ClaseSonidos(){}
