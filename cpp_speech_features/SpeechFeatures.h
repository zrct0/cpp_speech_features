#pragma once
#include "Array.h"
namespace cpp_speech_features {
	class SpeechFeatures
	{
	public:
		static Matzix mfcc(Azzay signal, int samplerate = 16000, accuracy winlen = 0.025, accuracy winstep = 0.01, int numcep = 13, int nfilt = 26, int nfft = 512, int lowfreq = 0, int highfreq = -1, accuracy preemph = 0.97, int ceplifter = 22, bool appendEnergy = true, void * winfunc = nullptr);
	private:
		static Matzix fbank(int &energy, Azzay signal, int samplerate = 16000, accuracy winlen = 0.025, accuracy winstep = 0.01, int nfilt = 26, int nfft = 512, int lowfreq = 0, int highfreq = -1, accuracy preemph = 0.97, void * winfunc = nullptr);
		static Azzay preemphasis(Azzay signal, accuracy coeff = 0.95);
		static Matzix framesig(Azzay sig, accuracy frame_len, accuracy frame_step, void * winfunc = nullptr);
		static Matzix tile(Azzay a, Azzay reps);
		static Matzix array_extract(Azzay a, Matzix indices);

	};
}

