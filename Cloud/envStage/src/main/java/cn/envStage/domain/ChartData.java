package cn.envStage.domain;

public class ChartData {
    private String datatime;

    public ChartData() {

    }

    public ChartData(String datatime) {
        this.datatime = datatime;
    }

    public String getDatatime() {
        return datatime;
    }

    public void setDatatime(String datatime) {
        this.datatime = datatime;
    }

    @Override
    public String toString() {
        return "ChartData{" +
                "datatime='" + datatime + '\'' +
                '}';
    }
}
