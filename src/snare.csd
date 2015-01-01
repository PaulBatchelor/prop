<CsoundSynthesizer>
<CsOptions>
-d -odac:system:playback_ -+rtaudio="jack" 
-B 4096 
-Lstdin
</CsOptions>
<CsInstruments>

sr	=	96000
ksmps	=	1
nchnls	=	2
0dbfs	=	1

instr 1	

a1 = rand(0.2) * expsegr(1, 0.1, 0.00001, 0.0001, 0.000001)
outs a1, a1

endin


</CsInstruments>
<CsScore>



</CsScore>
</CsoundSynthesizer>

