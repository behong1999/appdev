<?php
$peaks = $_POST['peaks'];
$max = $_POST['max'];
$today = date("Y-m-d H:i:s");
$record = $today.", Peaks: ".$peaks." & Maximum Value(dB): ".$max."\n";
$file = "sound.log";
if(file_exists($file))
    $fp = fopen($file,"a");
else
    $fp = fopen($file,"w");
fwrite($fp,$record);
fclose($fp);
?>

