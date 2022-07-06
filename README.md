# DataToAudio
Translates a file of data into an audio file suitable for writing to a data cassette.

`first_wav.c` creates a wav file from scratch.

## How to compile
```
$ gcc first_alsa.c -o first_alsa -lasound
$ ./first_alsa default
```

## How to Use (eventually)
1. Run the program datatoaudio filename
2. File filename.wav will be created.

## Resources
### ALSA
- [https://stackoverflow.com/questions/8485553/alsa-tutorial-required](https://stackoverflow.com/questions/8485553/alsa-tutorial-required)
- [https://www.alsa-project.org/main/index.php/Tutorials_and_Presentations](https://www.alsa-project.org/main/index.php/Tutorials_and_Presentations)
- [https://www.alsa-project.org/wiki/Main_Page](https://www.alsa-project.org/wiki/Main_Page)
- [https://alsa.opensrc.org/](https://alsa.opensrc.org/)
- [https://www.alsa-project.org/wiki/Tutorials_and_Presentations](https://www.alsa-project.org/wiki/Tutorials_and_Presentations)
- [https://jackaudio.org/](https://jackaudio.org/)
- [https://www.alsa-project.org/wiki/Documentation](https://www.alsa-project.org/wiki/Documentation)
- [http://equalarea.com/paul/alsa-audio.html#playex](http://equalarea.com/paul/alsa-audio.html#playex)
- [https://www.alsa-project.org/wiki/ALSA_User_Info](https://www.alsa-project.org/wiki/ALSA_User_Info)
- [https://github.com/sourcegod/alsatonic/blob/master/alsatonic.c](https://github.com/sourcegod/alsatonic/blob/master/alsatonic.c)

### WAV
- [https://codereview.stackexchange.com/questions/105272/writing-computer-generated-music-to-a-wav-file-in-c](https://codereview.stackexchange.com/questions/105272/writing-computer-generated-music-to-a-wav-file-in-c)
- [http://www-mmsp.ece.mcgill.ca/Documents/AudioFormats/WAVE/WAVE.html](http://www-mmsp.ece.mcgill.ca/Documents/AudioFormats/WAVE/WAVE.html)
- [https://docs.fileformat.com/audio/wav/#:~:text=The%20WAVE%20file%20format%2C%20being%20a%20subset%20of,format%3A%20Marks%20the%20file%20as%20a%20riff%20file.](https://docs.fileformat.com/audio/wav/#:~:text=The%20WAVE%20file%20format%2C%20being%20a%20subset%20of,format%3A%20Marks%20the%20file%20as%20a%20riff%20file.)
- [https://en.wikipedia.org/wiki/WAV](https://en.wikipedia.org/wiki/WAV)
- [https://www.bitsforbyte.com/2021/04/09/wave-file-format-specification/](https://www.bitsforbyte.com/2021/04/09/wave-file-format-specification/)
- [https://www.bitsforbyte.com/2021/10/08/wave-file-parser/](https://www.bitsforbyte.com/2021/10/08/wave-file-parser/)
- [https://www.headphonesty.com/2019/07/sample-rate-bit-depth-bit-rate/](https://www.headphonesty.com/2019/07/sample-rate-bit-depth-bit-rate/)
- [https://sound.stackexchange.com/questions/42371/what-signed-means-in-the-context-of-sound-adio-file-formats](https://sound.stackexchange.com/questions/42371/what-signed-means-in-the-context-of-sound-adio-file-formats)
- [https://stackoverflow.com/questions/32128206/what-does-interleaved-stereo-pcm-linear-int16-big-endian-audio-look-like](https://stackoverflow.com/questions/32128206/what-does-interleaved-stereo-pcm-linear-int16-big-endian-audio-look-like)
