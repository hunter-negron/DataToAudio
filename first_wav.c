#include <stdio.h>
#include <string.h>

typedef usample_t;

typedef struct wav_t {
    /* big */ char  chunkId[4];     // = "RIFF";
    /* lit */ int   chunkSize;      // file size minus 8 bytes
    /* big */ char  format[4];      // = "WAVE";
    
    /* big */ char  subchunk1Id[4]; // = "fmt ";
    /* lit */ int   subchunk1Size;
    /* lit */ short audioFormat;
    /* lit */ short numChannels;
    /* lit */ int   sampleRate;
    /* lit */ int   byteRate;
    /* lit */ short blockAlign;
    /* lit */ short bitsPerSample; // bits per sample per channel

    /* big */ char  subChunk2Id[4]; // = "data";
    /* lit */ int   subchunk2Size;
    /* lit */ 
} wav_t;

typedef int32_t sample_t; // 32 bits = 16 bits per sample * 2 channels

int main (int argc, char *argv[])
{
    printf("%lu\n", sizeof(wav_t));
    
    wav_t wav;
    memcpy(wav.chunkId, "RIFF", 4);
    //wav.chunkSize = ...
    memcpy(wav.format, "WAVE", 4);

    memcpy(wav.subchunk1Id, "fmt ", 4);
    wav.subchunk1Size = 16;
    wav.audioFormat = 1; // PCM
    wav.numChannels = 2; // interleaved
    wav.sampleRate = 44100;
    wav.byteRate = 176400; // (Sample Rate * Bits per Sample * Number of Channels) / 8
    wav.blockAlign = 4; // (Bits per Sample * Number of Channels) / 8
    wav.bitsPerSample = 16; // 
    memcpy(wav.subChunk2Id, "data", 4);
    //wav.subchunk2Size = ...



    return 0;
}