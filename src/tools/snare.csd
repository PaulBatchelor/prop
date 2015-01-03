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

;alwayson "keylisten"

instr 1	

a1 = rand(0.2) * expsegr(1, 0.03, 0.00001, 0.0001, 0.000001)
outs a1, a1

endin

instr keylisten

kres init -5

kres, kkeydown sensekey 
ival = 3
kval = 1
if(kval == 2) then
    schedule  1, 0, 1
endif

printk2 kres

endin

instr exit
    exitnow
endin

</CsInstruments>
<CsScore>
f 0 $INF

</CsScore>
</CsoundSynthesizer>

