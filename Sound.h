int NB0  = 31;
int NC1  = 33;
int NCS1 = 35;
int ND1  = 37;
int NDS1 = 39;
int NE1  = 41;
int NF1  = 44;
int NFS1 = 46;
int NG1  = 49;
int NGS1 = 52;
int NA1  = 55;
int NAS1 = 58;
int NB1  = 62;
int NC2  = 65;
int NCS2 = 69;
int ND2  = 73;
int NDS2 = 78;
int NE2  = 82;
int NF2  = 87;
int NFS2 = 93;
int NG2  = 98;
int NGS2 = 104;
int NA2  = 110;
int NAS2 = 117;
int NB2  = 123;
int NC3  = 131;
int NCS3 = 139;
int ND3  = 147;
int NDS3 = 156;
int NE3  = 165;
int NF3  = 175;
int NFS3 = 185;
int NG3  = 196;
int NGS3 = 208;
int NA3  = 220;
int AS3 = 233;
int NB3  = 247;
int NC4  = 262;
int NCS4 = 277;
int ND4  = 294;
int NDS4 = 311;
int NE4  = 330;
int NF4  = 349;
int NFS4 = 370;
int NG4  = 392;
int NGS4 = 415;
int NA4  = 440;
int NAS4 = 466;
int NB4  = 494;
int NC5  = 523;
int NCS5 = 554;
int ND5  = 587;
int NDS5 = 622;
int NE5  = 659;
int NF5  = 698;
int NFS5 = 740;
int NG5  = 784;
int NGS5 = 831;
int NA5  = 880;
int NAS5 = 932;
int NB5  = 988;
int NC6  = 1047;
int NCS6 = 1109;
int ND6  = 1175;
int NDS6 = 1245;
int NE6  = 1319;
int NF6  =1397;
int NFS6 = 1480;
int NG6  = 1568;
int NGS6 = 1661;
int NA6  = 1760;
int NAS6 = 1865;
int NB6  = 1976;
int NC7  = 2093;
int NCS7 = 2217;
int ND7  = 2349;
int NDS7 = 2489;
int NE7  = 2637;
int NF7  = 2794;
int NFS7 = 2960;
int NG7  = 3136;
int NGS7 = 3322;
int NA7  = 3520;
int NAS7 = 3729;
int NB7  = 3951;
int NC8  = 4186;
int NCS8 = 4435;
int ND8  = 4699;
int NDS8 = 4978;

int speakerPin = 5;

int currentNote = 0;

int numNotesStartup = 5;
int melodyStartup[] = {NB6, NB6, NB6, NGS6, NE7};
int NoteLengthStartup[] = {400, 400, 200, 200, 600};

int numNotesHit = 3;
int melodyHit[] = {NE5, NE5, NE5};
int NoteLengthHit[] = {400, 400, 400};


void startupSound()
{

  for (int i = 0; i < numNotesStartup; i++)
  {
    tone(speakerPin, melodyStartup[i], NoteLengthStartup[i]);
    delay(NoteLengthStartup[i]);
    noTone(speakerPin);
  }
   
}

void hitSound()
{

  for (int i = 0; i < numNotesHit; i++)
  {
    tone(speakerPin, melodyHit[i], NoteLengthHit[i]);
    delay(NoteLengthHit[i]);
    noTone(speakerPin);
  }
  
}

