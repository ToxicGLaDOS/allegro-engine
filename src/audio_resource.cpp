#include "audio_resource.h"
#include<allegro5/allegro_audio.h>



AudioResource::AudioResource(std::string path){
	// TODO: error check to make sure these things load properly
	ALLEGRO_PATH *body = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_append_path_component(body, "resources");
	
	ALLEGRO_PATH *tail = al_create_path(path.c_str());
	al_join_paths(body, tail);
		
	_sample = al_load_sample(al_path_cstr(body, '/'));
	_voice = al_create_voice(44100, ALLEGRO_AUDIO_DEPTH_INT16, ALLEGRO_CHANNEL_CONF_2);
	_mixer = al_create_mixer(44100, ALLEGRO_AUDIO_DEPTH_FLOAT32, ALLEGRO_CHANNEL_CONF_2);
	al_attach_mixer_to_voice(_mixer, _voice);
	_sampleInstance = al_create_sample_instance(NULL);
	al_set_sample(_sampleInstance, _sample);
	al_attach_sample_instance_to_mixer(_sampleInstance, _mixer);
	al_set_sample_instance_playmode(_sampleInstance, ALLEGRO_PLAYMODE_ONCE);
	
	
	al_destroy_path(body);
	al_destroy_path(tail);


}

void AudioResource::play(){
	al_set_sample_instance_position(_sampleInstance, 0);
	al_play_sample_instance(_sampleInstance);
}

void AudioResource::playFrom(unsigned int position){
	// TODO: make this by percentage or by seconds in
	// currently i have no idea what position represents
	al_set_sample_instance_position(_sampleInstance, position);
	al_play_sample_instance(_sampleInstance);
}

void AudioResource::setVolume(float volume){
	al_set_sample_instance_gain(_sampleInstance, _volume);
	_volume = volume;
}

void AudioResource::setPan(float pan){
	al_set_sample_instance_pan(_sampleInstance, _pan);
	_pan = pan;
}

void AudioResource::setSpeed(float speed){
	al_set_sample_instance_speed(_sampleInstance, _speed);
	_speed = speed;
}

void AudioResource::setLoop(bool loop){
	if(_loop){
		al_set_sample_instance_playmode(_sampleInstance, ALLEGRO_PLAYMODE_LOOP);
	}
	else{
		al_set_sample_instance_playmode(_sampleInstance, ALLEGRO_PLAYMODE_ONCE);
	}
	_loop = loop;
}

float AudioResource::volume() const{
	return _volume;
}

float AudioResource::pan() const{
	return _pan;
}

float AudioResource::speed() const{
	return _speed;
}

bool AudioResource::loop() const{
	return _loop;
}



