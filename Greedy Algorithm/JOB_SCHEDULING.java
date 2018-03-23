
import java.util.*;

/**
 *
 * @author Milan
 */
class Entries {

    private String names;
    private int deadline;
    private int profit;

    public Entries(String name, int deadline, int profit) {
        this.names = name;
        this.deadline = deadline;
        this.profit = profit;
    }

    public String getName() {
        return names;
    }

    public int getDeadline() {
        return deadline;
    }

    public int getProfit() {
        return profit;
    }
}

class Job_Scheduling {

    private LinkedList<Entries> AllLists;
    private String[] AllocatedTime;
    private int NumberofRequests;
    private int MaxTime;

    public Job_Scheduling(LinkedList<Entries> L) {

        AllLists = new LinkedList<Entries>();
        int length_L = L.indexOf(L.getLast()) + 1;
        Entries MostElagiableEntry;
        Entries ObjZero = new Entries("", 0, 0);

        for (int i = 0; i < length_L; i++) {
            MostElagiableEntry = L.get(i);
            int index_max = 0;
            for (int j = 0; j < length_L; j++) {
                if (MostElagiableEntry.getProfit() < L.get(j).getProfit()) {
                    MostElagiableEntry = L.get(j);
                    index_max = j;
                }
            }
            L.set(index_max, ObjZero);
            AllLists.addLast(MostElagiableEntry);
        }
        NumberofRequests = AllLists.indexOf(AllLists.getLast()) + 1;

        int max_time = AllLists.getFirst().getDeadline();
        for (int i = 1; i < length_L; i++) {
            if (max_time < AllLists.get(i).getDeadline()) {
                max_time = AllLists.get(i).getDeadline();
            }
        }
        this.MaxTime = max_time;
        AllocatedTime = new String[NumberofRequests];
    }

    public int maxProfit() {
        int MaxProfit = 0;
        AllocatedTime = new String[MaxTime];
        Arrays.fill(AllocatedTime, null);
        for (int i = 0; i < NumberofRequests; i++) {
            Entries CurrentEntry = AllLists.get(i);
            for (int j = 0; j < MaxTime - 1; j++) {
                int index = (CurrentEntry.getDeadline() - 1) - j;
                if (index >= 0 && null == AllocatedTime[index]) {
                    AllocatedTime[index] = CurrentEntry.getName();
                    MaxProfit += CurrentEntry.getProfit();
                    break;
                }
            }
        }
        return MaxProfit;
    }

    public void showListOfAllocatedEntries() {
        for (int i = 0; i < MaxTime; i++) {
            if (AllocatedTime[i] == null) {
                System.out.println("No Allocation in " + i + "-" + (i + 1));
            } else {
                System.out.println("Name of Candidate: " + AllocatedTime[i] + "\tTime Allocated: " + i + "-" + (i + 1));
            }
        }
    }
}

public class JOB_SCHEDULING {

    public static void main(String[] args) {

        Entries Application1 = new Entries("a", 4, 20);
        Entries Application2 = new Entries("b", 1, 10);
        Entries Application3 = new Entries("c", 1, 40);
        Entries Application4 = new Entries("d", 1, 30);
        Entries Application5 = new Entries("e", 3, 15);

        LinkedList<Entries> List = new LinkedList<Entries>();

        List.add(Application1);
        List.add(Application2);
        List.add(Application3);
        List.add(Application4);
        List.add(Application5);

        /*FOR ANALYSIS:*/ long startTime = System.currentTimeMillis();

        Job_Scheduling HollA = new Job_Scheduling(List);

        System.out.println("MAXIMUM PROFIT: " + HollA.maxProfit());
        /*FOR ANALYSIS:*/ long endTime = System.currentTimeMillis();

        System.out.println("\nTime Table of HallA:");
        HollA.showListOfAllocatedEntries();

        /*FOR ANALYSIS:*/ long executionTime = endTime - startTime;

        /*FOR ANALYSIS:*/ System.out.println("Total Execution Time: " + executionTime + " ms");
    }
}
