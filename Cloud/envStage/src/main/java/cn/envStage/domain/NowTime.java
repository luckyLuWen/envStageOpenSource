package cn.envStage.domain;

import java.io.Serializable;

public class NowTime implements Serializable {

    private String Msg;

    public NowTime(String msg) {
        this.Msg = msg;
    }

    public String getMsg() {
        return Msg;
    }

    public void setMsg(String msg) {
        Msg = msg;
    }

    @Override
    public String toString() {
        return "NowTime{" +
                "Msg='" + Msg + '\'' +
                '}';
    }
}
