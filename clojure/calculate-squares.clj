(defn calculate-squares [max]
  (take-while #(<= (* % %) max) (range)))

(doseq [i (calculate-squares 103)]
  (print (str i " ")))
(println)
