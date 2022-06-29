#include <stdio.h>
#include <stdlib.h>
#include <alsa/asoundlib.h>
#include <math.h>

// gcc first_alsa.c -o first_alsa -lasound
// ./first_alsa default
	      
int main (int argc, char *argv[])
{
	int i;
	int err;
	short buf[400];
	snd_pcm_t *playback_handle;
	snd_pcm_hw_params_t *hw_params;

	/* setup */
	if ((err = snd_pcm_open (&playback_handle, argv[1], SND_PCM_STREAM_PLAYBACK, 0)) < 0) {
		fprintf (stderr, "cannot open audio device %s (%s)\n", 
			 argv[1],
			 snd_strerror (err));
		exit (1);
	}
	   
	if ((err = snd_pcm_hw_params_malloc (&hw_params)) < 0) {
		fprintf (stderr, "cannot allocate hardware parameter structure (%s)\n",
			 snd_strerror (err));
		exit (1);
	}
			 
	if ((err = snd_pcm_hw_params_any (playback_handle, hw_params)) < 0) {
		fprintf (stderr, "cannot initialize hardware parameter structure (%s)\n",
			 snd_strerror (err));
		exit (1);
	}

	if ((err = snd_pcm_hw_params_set_access (playback_handle, hw_params, SND_PCM_ACCESS_RW_INTERLEAVED)) < 0) {
		fprintf (stderr, "cannot set access type (%s)\n",
			 snd_strerror (err));
		exit (1);
	}

	if ((err = snd_pcm_hw_params_set_format (playback_handle, hw_params, SND_PCM_FORMAT_S16_LE)) < 0) {
		fprintf (stderr, "cannot set sample format (%s)\n",
			 snd_strerror (err));
		exit (1);
	}

	int val = 44100;
	if ((err = snd_pcm_hw_params_set_rate_near (playback_handle, hw_params, &val, 0)) < 0) {
		fprintf (stderr, "cannot set sample rate (%s)\n",
			 snd_strerror (err));
		exit (1);
	}

	if ((err = snd_pcm_hw_params_set_channels (playback_handle, hw_params, 2)) < 0) {
		fprintf (stderr, "cannot set channel count (%s)\n",
			 snd_strerror (err));
		exit (1);
	}

	if ((err = snd_pcm_hw_params (playback_handle, hw_params)) < 0) {
		fprintf (stderr, "cannot set parameters (%s)\n",
			 snd_strerror (err));
		exit (1);
	}

	snd_pcm_hw_params_free (hw_params);

	if ((err = snd_pcm_prepare (playback_handle)) < 0) {
		fprintf (stderr, "cannot prepare audio interface for use (%s)\n",
			 snd_strerror (err));
		exit (1);
	}
	
	for(int i1 = 100, i2 = 200; i1 < 200; i1++, i2--) {
		buf[i1-100] = i1;
		buf[i1] = i2;
		buf[i1+100] = 200-i1;
		buf[i1+200] = 200-i2;
	}
	
	
	//for(int i = 0; i < 400; i++)
		//printf("%hd\n", buf[i]);
	
	/* the actual sound code */
	for (i = 0; i < 3000; ++i) {
		if ((err = snd_pcm_writei (playback_handle, buf, 400)) != 400) {
			fprintf (stderr, "write to audio interface failed (%s)\n",
				 snd_strerror (err));
			exit (1);
		}
	}

	/* clean up */
	snd_pcm_close (playback_handle);
	exit (0);
}
