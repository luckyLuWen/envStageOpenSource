package cn.envStage.domain;

public class Devices_num {
    private String userID;
    private int num;
    private int subNum;

    public Devices_num(){}

    public Devices_num(String userID, int num, int subNum) {
        this.userID = userID;
        this.num = num;
        this.subNum = subNum;
    }

    public String getUserID() {
        return userID;
    }

    public void setUserID(String userID) {
        this.userID = userID;
    }

    public int getNum() {
        return num;
    }

    public void setNum(int num) {
        this.num = num;
    }

    public int getSubNum() {
        return subNum;
    }

    public void setSubNum(int subNum) {
        this.subNum = subNum;
    }

    @Override
    public String toString() {
        return "Devices_num{" +
                "userID='" + userID + '\'' +
                ", num=" + num +
                ", subNum=" + subNum +
                '}';
    }
}
