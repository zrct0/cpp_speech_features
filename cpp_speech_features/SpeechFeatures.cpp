#include "pch.h"
#include "SpeechFeatures.h"

namespace cpp_speech_features {

	Matzix SpeechFeatures::mfcc(Azzay signal, int samplerate, accuracy winlen, accuracy winstep, int numcep, int nfilt, int nfft, int lowfreq, int highfreq, accuracy preemph, int ceplifter, bool appendEnergy, void * winfunc)
	{
		int energy;
		fbank(energy, signal, samplerate, winlen, winstep, nfilt, nfft, lowfreq, highfreq, preemph, winfunc);
		return nullptr;
	}
	Matzix SpeechFeatures::fbank(int & energy, Azzay signal, int samplerate, accuracy winlen, accuracy winstep, int nfilt, int nfft, int lowfreq, int highfreq, accuracy preemph, void * winfunc)
	{
		highfreq = highfreq == -1 ? samplerate / 2 : highfreq;		
		signal = preemphasis(signal, preemph);		
		Matzix frames = framesig(signal, winlen*samplerate, winstep*samplerate, winfunc);
		return nullptr;
	}

	Azzay SpeechFeatures::preemphasis(Azzay signal, accuracy coeff) {
		//numpy.append(signal[0],signal[1:]-coeff*signal[:-1])			
		return Array::concatenate(signal->get(0), signal->skip(1)->subtract(signal->skip(-1)->multiply(coeff)));
	}
	Matzix SpeechFeatures::framesig(Azzay sig, accuracy frame_len, accuracy frame_step, void * winfunc)
	{	
		int slen = sig->getSize();
		frame_len = (accuracy)round(frame_len);
		frame_step = (accuracy)round(frame_step);
		int numframes;
		if (slen <= frame_len) {
			numframes = 1;
		}
		else {
			numframes = (int)(1 + ceil((1.0*slen - frame_len) / frame_step));
		}
		int padlen = (int)((numframes - 1)*frame_step + frame_len);
		Azzay zeros = create_azzay(padlen - slen);
		Azzay padsignal = sig->concatenate(zeros);
		Azzay tileArg1 = Array::arange(0, frame_len);
		Azzay tileArg2 = Array::arange(0, numframes*frame_step, frame_step);		
		Matzix tile1 = tile(tileArg1, create_azzay_by_array(2, (accuracy)numframes, 1.0));
		Matzix tile2 = tile(tileArg2, create_azzay_by_array(2, (accuracy)frame_len, 1.0 ))->T();
		Matzix indices = tile1->add(tile2);		
		Matzix framesj = array_extract(padsignal, indices);		
		return framesj;
	}

	Matzix SpeechFeatures::tile(Azzay a, Azzay reps)
	{
		int aLen = a->getSize();
		int reps0 = (int)(reps->get(0));
		if (reps->get(1) != 1) {
			throw std::exception("仅支持reps 为 (N, 1)的情况");
		}
		Matzix b = a->concatenate(a);		
		for (int i = 0; i < reps0 - 2; i++) {
			b = b->concatenate(a);			
		}			
		return b->reshape(aLen, reps0);
	}	

	Matzix SpeechFeatures::array_extract(Azzay a, Matzix indices)
	{	
		int indices_rows_count = indices->getRow();
		Matzix a2 = create_matzix(indices->getColumn(), indices->getRow());
		Azzay ixs;
		int ixs_size;
		int ix;
		for (int i = 0; i < indices_rows_count; ++i) {
			ixs = indices->getRow(i);
			ixs_size = ixs->getSize();			
			for (int j = 0; j < ixs_size; ++j) {
				ix = (int)(ixs->get(j));
				a2->set(i, j, a->get(ix));
			}
		}
		return a2;
	}
}
