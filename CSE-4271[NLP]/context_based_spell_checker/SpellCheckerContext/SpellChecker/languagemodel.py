#!/usr/bin/env python
class CalculationLM:
	def __init__(self):
		import os
		import kenlm
		self.LM = os.path.join(os.path.dirname(__file__), '..','trained_model','text.arpa')
		self.model = kenlm.LanguageModel(self.LM)
		self.obj = kenlm
		print('{0}-gram model'.format(self.model.order))

	def calculate_probability(self,line):

		sentence = line
		#print(sentence)
		#print(self.model.score(sentence))
		value = self.model.score(sentence)

		# Check that total full score = direct score
		def score(s):
			return sum(prob for prob, _, _ in self.model.full_scores(s))

		assert (abs(score(sentence) - self.model.score(sentence)) < 1e-3)

		# Show scores and n-gram matches
		words = ['<s>'] + sentence.split() + ['</s>']
		for i, (prob, length, oov) in enumerate(self.model.full_scores(sentence)):
			#print('{0} {1}: {2}'.format(prob, length, ' '.join(words[i+2-length:i+2])))
			if oov:
				#print('\t"{0}" is an OOV'.format(words[i+1]))
				pass
		# Find out-of-vocabulary words
		for w in words:
			if not w in self.model:
				#print('"{0}" is an OOV'.format(w))
				pass
		#Stateful query
		state = self.obj.State()
		state2 = self.obj.State()
		#Use <s> as context.  If you don't want <s>, use model.NullContextWrite(state).
		self.model.BeginSentenceWrite(state)
		accum = 0.0
		accum += self.model.BaseScore(state, "a", state2)
		accum += self.model.BaseScore(state2, "sentence", state)
		#score defaults to bos = True and eos = True.  Here we'll check without the end
		#of sentence marker.
		assert (abs(accum - self.model.score("a sentence", eos = False)) < 1e-3)
		accum += self.model.BaseScore(state, "</s>", state2)
		assert (abs(accum - self.model.score("a sentence")) < 1e-3)
		self.sentence_probability = value
	 	return self.sentence_probability
