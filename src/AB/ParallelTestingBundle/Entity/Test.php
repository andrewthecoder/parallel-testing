<?php

namespace AB\ParallelTestingBundle\Entity;

use Doctrine\ORM\Mapping as ORM;

/**
 * Test
 *
 * @ORM\Table()
 * @ORM\Entity(repositoryClass="AB\ParallelTestingBundle\Entity\TestRepository")
 */
class Test
{
    /**
     * @var integer
     *
     * @ORM\Column(name="id", type="integer")
     * @ORM\Id
     * @ORM\GeneratedValue(strategy="AUTO")
     */
    private $id;

    /**
     * @var string
     *
     * @ORM\Column(name="type", type="string", length=255)
     */
    private $type;

    /**
     * @var integer
     *
     * @ORM\Column(name="lowerLimit", type="integer")
     */
    private $lowerLimit;

    /**
     * @var integer
     *
     * @ORM\Column(name="upperLimit", type="integer")
     */
    private $upperLimit;

    /**
     * @var string
     *
     * @ORM\Column(name="status", type="string", length=255)
     */
    private $status;

    /**
     * @var string
     *
     * @ORM\Column(name="programOutput", type="text", nullable=true)
     */
    private $programOutput;

    /**
     * @var string
     *
     * @ORM\Column(name="fullCommand", type="text", nullable=true)
     */
    private $fullCommand;

    /**
     * @var integer
     *
     * @ORM\Column(name="processPID", type="integer", nullable=true)
     */
    private $processPID;

    /**
     * @var decimal
     *
     * @ORM\Column(name="systemRunTime", type="decimal", precision=7, scale=2, nullable=true)
     */
    private $systemRunTime;

    /**
     * @var decimal
     *
     * @ORM\Column(name="clockRunTime", type="decimal", precision=7, scale=2, nullable=true)
     */
    private $clockRunTime;

    /**
     * @var decimal
     *
     * @ORM\Column(name="cpuPercent", type="decimal", precision=7, scale=2, nullable=true)
     */
    private $cpuPercent;


    /**
     * Get id
     *
     * @return integer 
     */
    public function getId()
    {
        return $this->id;
    }

    /**
     * Set type
     *
     * @param string $type
     * @return Test
     */
    public function setType($type)
    {
        $this->type = $type;

        return $this;
    }

    /**
     * Get type
     *
     * @return string 
     */
    public function getType()
    {
        return $this->type;
    }

    /**
     * Set lowerLimit
     *
     * @param integer $lowerLimit
     * @return Test
     */
    public function setLowerLimit($lowerLimit)
    {
        $this->lowerLimit = $lowerLimit;

        return $this;
    }

    /**
     * Get lowerLimit
     *
     * @return integer 
     */
    public function getLowerLimit()
    {
        return $this->lowerLimit;
    }

    /**
     * Set upperLimit
     *
     * @param integer $upperLimit
     * @return Test
     */
    public function setUpperLimit($upperLimit)
    {
        $this->upperLimit = $upperLimit;

        return $this;
    }

    /**
     * Get upperLimit
     *
     * @return integer 
     */
    public function getUpperLimit()
    {
        return $this->upperLimit;
    }

    /**
     * Set processPID
     *
     * @param integer $processPID
     * @return Test
     */
    public function setProcessPID($processPID)
    {
        $this->processPID = $processPID;

        return $this;
    }

    /**
     * Get processPID
     *
     * @return integer 
     */
    public function getProcessPID()
    {
        return $this->processPID;
    }

    /**
     * Set status
     *
     * @param string $status
     * @return Test
     */
    public function setStatus($status)
    {
        $this->status = $status;

        return $this;
    }

    /**
     * Get status
     *
     * @return string 
     */
    public function getStatus()
    {
        return $this->status;
    }

    /**
     * Set programOutput
     *
     * @param string $programOutput
     * @return Test
     */
    public function setProgramOutput($programOutput)
    {
        $this->programOutput = $programOutput;

        return $this;
    }

    /**
     * Get programOutput
     *
     * @return string 
     */
    public function getProgramOutput()
    {
        return $this->programOutput;
    }

    /**
     * Set fullCommand
     *
     * @param string $fullCommand
     * @return Test
     */
    public function setFullCommand($fullCommand)
    {
        $this->fullCommand = $fullCommand;

        return $this;
    }

    /**
     * Get fullCommand
     *
     * @return string 
     */
    public function getFullCommand()
    {
        return $this->fullCommand;
    }

    /**
     * Set systemRunTime
     *
     * @param decimal $systemRunTime
     * @return Test
     */
    public function setSystemRunTime($systemRunTime)
    {
        $this->systemRunTime = $systemRunTime;

        return $this;
    }

    /**
     * Get systemRunTime
     *
     * @return decimal 
     */
    public function getSystemRunTime()
    {
        return $this->systemRunTime;
    }

    /**
     * Set clockRunTime
     *
     * @param decimal $clockRunTime
     * @return Test
     */
    public function setClockRunTime($clockRunTime)
    {
        $this->clockRunTime = $clockRunTime;

        return $this;
    }

    /**
     * Get clockRunTime
     *
     * @return decimal 
     */
    public function getClockRunTime()
    {
        return $this->clockRunTime;
    }

    /**
     * Set cpuPercent
     *
     * @param decimal $cpuPercent
     * @return Test
     */
    public function setCpuPercent($cpuPercent)
    {
        $this->cpuPercent = $cpuPercent;

        return $this;
    }

    /**
     * Get cpuPercent
     *
     * @return decimal 
     */
    public function getCpuPercent()
    {
        return $this->cpuPercent;
    }
}
