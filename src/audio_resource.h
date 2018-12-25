#ifndef AUDIO_RESOURCE_H_
#define AUDIO_RESOURCE_H_

#include<string>
#include<allegro5/allegro_audio.h>


class AudioResource{
	public:
		AudioResource(std::string path);
		
		void play();
		void playFromSeconds(unsigned int position);
		void playFromPercentage(float percentage);

		void setVolume(float volume);
		void setPan(float pan);
		void setSpeed(float speed);
		void setLoop(bool loop);

		float volume() const;
		float pan() const;
		float speed() const;
		bool loop() const;

	private:
		// What you load the sound file into this is the data
		ALLEGRO_SAMPLE* _sample;
		// What plays the sound file (the hardware or software)
		ALLEGRO_VOICE* _voice;
		// What you can actually play
		ALLEGRO_SAMPLE_INSTANCE* _sampleInstance;
		// A thing that can mix together with other mixers
		ALLEGRO_MIXER* _mixer;

		unsigned int _sampleRate = 44100;
		float _volume = 1, _pan = 0, _speed = 1;
		bool _loop = false;

};



#endif
