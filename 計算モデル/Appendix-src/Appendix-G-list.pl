 empty([]).             % 空リストであれば真
 head([H|_], H).        % Hが頭部であれば真
 tail([_|Tail], Tail).  % Tailが尾部であれば真
