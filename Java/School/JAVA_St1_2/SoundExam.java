/*
class SoundExam{
    public static void main(String[] args){
        Sound radio = new Radio();
        Sound tv = new TV();

        radio.SoundUp(5);
        Radio r = (Radio)radio;
        System.out.println(r.getLevel());

        tv.SoundUp(5);
        TV t = (TV)tv;
        System.out.println(t.getLevel());
    }
}
interface Sound{
    public void SoundUp(int level);
    public void SoundDown(int level);
}
class TV implements Sound{
    private int SndLevel;

    public TV(){
        SndLevel = 0;
    }

    public void SoundUp(int level){
        SndLevel += level;
    }
    public void SoundDown(int level){
        SndLevel -= level;
        if(SndLevel < 0) SndLevel = 0;
    }
    public int getLevel(){
        return SndLevel;
    }
}
class Radio implements Sound {
    private int SndLevel;

    public Radio() {
        SndLevel = 0;
    }

    public void SoundUp(int level) {
        SndLevel += level;
    }

    public void SoundDown(int level) {
        SndLevel -= level;
        if (SndLevel < 0) SndLevel = 0;
    }
    public int getLevel(){
        return SndLevel;
    }
}*/
