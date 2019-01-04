#include "audio_resource.h"
#include "exceptions.h"
#include<allegro5/allegro_audio.h>
#include<fstream>


AudioResource::AudioResource(std::string path){
	ALLEGRO_PATH *body = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_append_path_component(body, "resources");
	
	ALLEGRO_PATH *tail = al_create_path(path.c_str());
	al_join_paths(body, tail);
	
	const char* file_path = al_path_cstr(body, '/');

	if(std::ifstream(file_path)){
		_sample = al_load_sample(file_path);
		if(_sample == NULL){
			std::string err = std::string("Audio with path: ");
			err.append(file_path);
			err.append(" failed to load");
			throw ResourceLoadException(err);
		}
		_voice = al_create_voice(_sampleRate, ALLEGRO_AUDIO_DEPTH_INT16, ALLEGRO_CHANNEL_CONF_2);
		if(_voice == NULL){
			throw AllegroCreationException("Allegro voice failed to be created");
		}
		_mixer = al_create_mixer(_sampleRate, ALLEGRO_AUDIO_DEPTH_FLOAT32, ALLEGRO_CHANNEL_CONF_2);
		if(_mixer == NULL){
			throw AllegroCreationException("Allegro mixer failed to be created");
		}
		if(!al_attach_mixer_to_voice(_mixer, _voice)){
			throw AudioAttachException("Failed to attah mixer to voice");
		}
		_sampleInstance = al_create_sample_instance(NULL);
		if(_sampleInstance == NULL){
			throw AllegroCreationException("Allegro sample instance failed to be create");
		}
		if(!al_set_sample(_sampleInstance, _sample)){
			// This might not be the most sensical exception to throw
			// but I don't want to clutter things with too many kinds of exceptions
			throw AudioAttachException("Failed to attach sample instance to sample");
		}
		if(!al_attach_sample_instance_to_mixer(_sampleInstance, _mixer)){
			throw AudioAttachException("Failed to attach sample instance to mixer");
		}
		al_set_sample_instance_playmode(_sampleInstance, ALLEGRO_PLAYMODE_ONCE);
	}
	else{
		std::string err = std::string("No file exists at path ");
		err.append(file_path);
		throw ResourceLoadException(err);
	}
	
	al_destroy_path(body);
	al_destroy_path(tail);


}

void AudioResource::play(){
	al_set_sample_instance_position(_sampleInstance, 0);
	al_play_sample_instance(_sampleInstance);
}

void AudioResource::playFromSeconds(unsigned int seconds){
	unsigned int position = _sampleRate * seconds;
	al_set_sample_instance_position(_sampleInstance, position);
	al_play_sample_instance(_sampleInstance);
}

void AudioResource::playFromPercentage(float percentage){
	if(percentage > 1)
		percentage = 1;
	else if(percentage < 0)
		percentage = 0;
	unsigned int length = al_get_sample_instance_length(_sampleInstance);
	int position = length * percentage;
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



